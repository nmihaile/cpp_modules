/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonetaryValue.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:22:57 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/13 19:07:57 by nmihaile         ###   ########.fr       */
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
	__uint128_t result = static_cast<__uint128_t>(m_value) * static_cast<__uint128_t>(rhs.m_value);
	result /= m_scale;
	m_value = static_cast<uint64_t>(result);
	return (*this);
}

MonetaryValue	MonetaryValue::operator*(const MonetaryValue& rhs) const
{
	__uint128_t result = static_cast<__uint128_t>(m_value) * static_cast<__uint128_t>(rhs.m_value);
	result /= m_scale;
	return ( MonetaryValue(static_cast<uint64_t>(result)) );
}

uint64_t	MonetaryValue::getScaledValue(void) const
{
	return (m_value);
}

double		MonetaryValue::toDouble(void) const
{
	double d_value = static_cast<double>(m_value) / m_scale;
	return ( d_value );
}

std::string	MonetaryValue::toStr(void) const
{
	std::ostringstream	os;
	os << toDouble();
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

	m_value = convertIntoScale(_value);
}

uint64_t	MonetaryValue::convertIntoScale(const std::string& _value)
{
	uint64_t	scaled_value = 0;

	std::size_t	pos = _value.find('.');
	if (pos == std::string::npos)
		scaled_value = strToType<uint64_t>(_value) * m_scale;
	else
	{
		if (pos == 0 || pos == _value.length() - 1)
			throw ( std::runtime_error("incomplete integral or fractional part of monetary value") );

		double d_value = strToType<double>(_value);
		scaled_value = static_cast<uint64_t>(d_value * m_scale);
	}

	return (scaled_value);
}
