/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonetaryValue.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:22:57 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/11 13:00:14 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonetaryValue.hpp"

MonetaryValue::MonetaryValue() : m_value(0)
{
}

MonetaryValue::MonetaryValue(uint64_t _value) : m_value(_value)
{
}

MonetaryValue::MonetaryValue(const std::string& _value) : m_value(0)
{
	parseMonetaryValueStr(_value);
}

MonetaryValue::MonetaryValue(const MonetaryValue& other) : m_value(other.m_value)
{
}

MonetaryValue::~MonetaryValue()
{
}


MonetaryValue&	MonetaryValue::operator=(const MonetaryValue& rhs)
{
	if (this != &rhs)
		m_value = rhs.m_value;
	return (*this);
}

MonetaryValue&	MonetaryValue::operator*=(const MonetaryValue& rhs)
{
	m_value = (m_value * rhs.m_value) / 100;
	return (*this);
}

MonetaryValue	MonetaryValue::operator*(const MonetaryValue& rhs)
{
	uint64_t result = (m_value * rhs.m_value) / 100;
	return ( MonetaryValue(result) );
}

uint64_t	MonetaryValue::getValueCents(void) const
{
	return (m_value);
}

double		MonetaryValue::getValueDouble(void) const
{
	return (m_value / 100.0);
}

std::string	MonetaryValue::getValueStr(void) const
{
	std::ostringstream	os;
	os << (m_value / 100) << '.' << std::setw(2) << std::setfill('0') << (m_value % 100);
	return (os.str());
}


/* ************************************************************************** */
/* ************************************************************************** */


void	MonetaryValue::parseMonetaryValueStr(const std::string& _value)
{
	int	dec_count = 0;
	for (std::string::const_iterator it = _value.begin(); it < _value.end(); ++it)
	{
		if (!std::isdigit(*it) && !(*it == '.'))
			throw ( std::runtime_error("non monetary character detected, allowd [0..9|.]") );
		if (*it == '.')
			++dec_count;
		if (dec_count > 1)
			throw ( std::runtime_error("found multiple decimal points, only one allowed") );
	}

	m_value = convertToCents(_value);
}

uint64_t	MonetaryValue::convertToCents(const std::string& _value)
{
	std::pair<uint64_t, uint64_t>	monetaryValue(0, 0);

	std::size_t	pos = _value.find('.');
	if (pos == std::string::npos)
		monetaryValue.first = strToUint64(_value);
	else
	{
		if (pos == 0 || pos == _value.length() - 1)
			throw ( std::runtime_error("incomplete integral or fractional part of monetary value") );

		const std::string	integral = _value.substr(0, pos);
		const std::string	fractional = _value.substr(pos + 1);
		
		monetaryValue.first = strToUint64(integral);
		
		if (fractional.length() > 2)
			throw ( std::runtime_error("too many decimal places on monetary value, only two allowed") );

		monetaryValue.second = strToUint64(fractional);

		if (fractional.length() == 1)
			monetaryValue.second *= 10;
	}
		
	return (monetaryValue.first * 100 + monetaryValue.second);
}

uint64_t	MonetaryValue::strToUint64(const std::string& _value)
{
	std::stringstream	ss(_value);
	uint64_t			parsedValue;

	ss >> parsedValue;
	if (ss.fail())
		throw ( std::runtime_error("failed to convert str to monetary value") );

	return (parsedValue);
}
