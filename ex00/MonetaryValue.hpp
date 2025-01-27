/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonetaryValue.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:22:59 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/27 19:12:00 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MONETARYVALUE_HPP
#define MONETARYVALUE_HPP

#include <cstdint>
#include <string>
#include <sstream>
#include <iomanip>

class MonetaryValue
{
public:
	MonetaryValue();
	MonetaryValue(uint64_t _value);
	MonetaryValue(std::string& _value);
	MonetaryValue(const MonetaryValue& other);
	~MonetaryValue();

	MonetaryValue&	operator=(const MonetaryValue& rhs);
	uint64_t		operator*=(const uint64_t& rhs);

	uint64_t	getValueCents(void) const;
	double		getValueDouble(void) const;
	std::string	getValueStr(void) const;
	
private:
	uint64_t	m_value;

	void	parseMonetaryValueStr(std::string& _value);
};

#endif
