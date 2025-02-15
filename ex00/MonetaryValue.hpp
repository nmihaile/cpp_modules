/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonetaryValue.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:22:59 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/13 18:57:19 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MONETARYVALUE_HPP
#define MONETARYVALUE_HPP

#include <cstdint>
#include <string>
#include <sstream>
#include <iomanip>
#include <utility>

class MonetaryValue
{
public:
	MonetaryValue();
	MonetaryValue(uint64_t _value);
	MonetaryValue(const std::string& _value);
	MonetaryValue(const MonetaryValue& other);
	~MonetaryValue();

	MonetaryValue&	operator=(const MonetaryValue& rhs);
	MonetaryValue&	operator*=(const MonetaryValue& rhs);
	MonetaryValue	operator*(const MonetaryValue& rhs) const;

	uint64_t		getScaledValue(void) const;
	double			toDouble(void) const;
	std::string		toStr(void) const;
	
private:
	static const uint64_t	m_scale = 100000000;	// scale: BTC in satoshis AND, CURRENCY in nano_value
	uint64_t				m_value;

	void		parseMonetaryValueStr(const std::string& _value);
	uint64_t	convertIntoScale(const std::string& _value);
	template <typename T>
	T			strToType(const std::string& _value);
	
};

#include "MonetaryValue.tpp"

#endif
