/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:22:04 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/27 15:06:22 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <sstream>
#include <ctime>
#include <stdexcept>

class Date
{
public:
	Date();
	Date(std::string& _date);
	Date(const Date& other);
	~Date();

	Date&		operator=(const Date& rhs);
	std::time_t	toUnixTimestamp();
	std::string	toString(void) const;
	
private:
	std::tm		m_date;

	void	parseDateStr(std::string& _date);
	bool	validateDate() const;
	bool	isLeapYear(int year) const;
};

#endif