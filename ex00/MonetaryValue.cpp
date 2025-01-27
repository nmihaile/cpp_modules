/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonetaryValue.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:22:57 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/27 19:17:55 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonetaryValue.hpp"

MonetaryValue::MonetaryValue() : m_value(0)
{
}

MonetaryValue::MonetaryValue(uint64_t _value) : m_value(_value)
{
}

MonetaryValue::MonetaryValue(std::string& _value) : m_value(0)
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

uint64_t	MonetaryValue::operator*=(const uint64_t& rhs)
{
	m_value = (m_value * rhs) / 100;
	return (m_value);
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


void	MonetaryValue::parseMonetaryValueStr(std::string& _value)
{
	int	dec_count = 0;
	for (std::string::iterator it = _value.begin(); it < _value.end(); ++it)
	{
		if (!std::isdigit(*it) && !(*it == '.'))
			throw ( std::runtime_error("non monetary character detected, allowd [0..9|.]") );
		if (*it == '.')
			++dec_count;
		if (dec_count > 1)
			throw ( std::runtime_error("found multiple decimal points, only one allowed") );
	}

	std::stringstream	ss(_value);
	double				parsedValue;

	ss >> parsedValue;
	if (ss.fail())
		throw ( std::runtime_error("failed to convert str to monetary value") );

	// lightweight safeguard for negative values
	if (parsedValue < 0)
		throw ( std::runtime_error("negative monetary value not allowd") );
		
	m_value = static_cast<uint64_t>(parsedValue * 100.00);
}
