/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:22:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/28 15:14:57 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() : m_date(std::tm{})
{
}

Date::Date(std::string& _date) : m_date(std::tm{})
{
	parseDateStr(_date);
}

Date::Date(const Date& other)
{
	if (this != &other)
		this->m_date = other.m_date;
}

Date::~Date()
{}

Date&	Date::operator=(const Date& rhs)
{
	if (this != &rhs)
		this->m_date = rhs.m_date;
	return (*this);
}

std::time_t	Date::toUnixTimestamp()
{
	return (std::mktime(&m_date));
}

std::string	Date::toString(void) const
{
	std::stringstream	ss;

	ss	<< std::setw(4) << std::setfill('0') <<  m_date.tm_year + 1900 << '-'
		<< std::setw(2) << (m_date.tm_mon + 1) << '-'
		<< std::setw(2) << m_date.tm_mday;
	return (ss.str());
}

bool	Date::isLeapYear() const
{
	int _year = m_date.tm_year + 1900;
	return (( _year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0) ));
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Date::parseDateStr(std::string& _date)
{
	std::stringstream	ss(_date);
	char				delimiter;

	if (_date.length() != 10)
		throw ( std::runtime_error("wrong length of date (expecet format YYYY-MM-DD)") );

	ss >> m_date.tm_year;
	if (ss.fail())
		throw ( std::runtime_error("failed to parse year") );
	m_date.tm_year -= 1900;

	ss >> delimiter;
	if (ss.fail())
		throw ( std::invalid_argument("failed to parsing delimiter") );
	else if (delimiter != '-')
		throw ( std::invalid_argument("wrong delimiter in date") );

	ss >> m_date.tm_mon;
	if (ss.fail())
		throw ( std::invalid_argument("failed parsing month") );
	--m_date.tm_mon;

	ss >> delimiter;
	if (ss.fail())
		throw ( std::invalid_argument("failed to parsing delimiter") );
	else if (delimiter != '-')
		throw ( std::invalid_argument("wrong delimiter in date") );

	ss >> m_date.tm_mday;
	if (ss.fail())
		throw ( std::invalid_argument("invalid day") );

	validateDate();

}

bool	Date::validateDate() const
{
	int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (m_date.tm_mon < 0 || m_date.tm_mon > 11)
		throw ( std::invalid_argument("month out of range 01-12") );

	if (isLeapYear())
		days_in_month[1] = 29;

	if (m_date.tm_mday < 1 || m_date.tm_mday > days_in_month[m_date.tm_mon])
		throw ( std::invalid_argument("day out of range 01-" + std::to_string(days_in_month[m_date.tm_mon])) );

	return (true);
}
