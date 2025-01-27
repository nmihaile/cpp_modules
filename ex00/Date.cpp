/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:22:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/27 15:06:33 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() : m_date((std::tm){0, 0, 0, 0, 0, 70, 0, 1})
{
}

Date::Date(std::string& _date) : m_date((std::tm){0})
{
	parseDateStr(_date);
}

Date::Date(const Date& other)
{
	if (this != &other)
	{}
}

Date::~Date()
{}

Date&	Date::operator=(const Date& rhs)
{
	if (this != &rhs)
	{}
	return (*this);
}

std::time_t	Date::toUnixTimestamp()
{
	return (std::mktime(&m_date));
}

std::string	Date::toString(void) const
{
	std::stringstream	ss;

	ss << m_date.tm_year << '-' << (m_date.tm_mon + 1) << '-' << m_date.tm_mday;
	return (ss.str());
}


/* ************************************************************************** */
/* ************************************************************************** */

void	Date::parseDateStr(std::string& _date)
{
	std::stringstream	ss(_date);
	char				delimiter;

	ss >> m_date.tm_year;
	if (ss.fail())
		throw ( std::runtime_error("invalid year") );
	m_date.tm_year -= 1900;

	ss >> delimiter;
	if (ss.fail())
		throw ( std::invalid_argument("invalid date format") );
	else if (delimiter != '-')
		throw ( std::invalid_argument("invalid delimiter in date") );

	ss >> m_date.tm_mon;
	if (ss.fail())
		throw ( std::invalid_argument("invalid month") );
	--m_date.tm_mon;

	ss >> delimiter;
	if (ss.fail())
		throw ( std::invalid_argument("invalid date format") );
	else if (delimiter != '-')
		throw ( std::invalid_argument("invalid delimiter in date") );

	ss >> m_date.tm_mday;
	if (ss.fail())
		throw ( std::invalid_argument("invalid day") );

	validateDate();

}

bool	Date::validateDate() const
{
	int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (m_date.tm_mon < 0 || m_date.tm_mon > 11)
		throw ( std::invalid_argument("invalid month, out of range 01-12") );

	if (isLeapYear(m_date.tm_year))
		days_in_month[1] = 29;

	if (m_date.tm_mday < 1 || m_date.tm_mday > days_in_month[m_date.tm_mon])
		throw ( std::invalid_argument("invalid day, out of range 01-" + std::to_string(days_in_month[m_date.tm_mon])) );

}

bool	Date::isLeapYear(int year) const
{
	year += 1900;
	return (( year % 4 == 0 && (year % 100 != 0 && year & 400 == 0) ));
}
