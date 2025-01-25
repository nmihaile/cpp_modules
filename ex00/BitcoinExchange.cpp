/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/25 12:51:22 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	if (this != &other)
	{
	}
}

BitcoinExchange::~BitcoinExchange()
{
}


BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		// TODO: handle member variables
	}
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	BitcoinExchange::loadPriceTable(std::string _dataFile)
{
	std::ifstream	fs;

	m_dataFile = _dataFile;

	fs.open(m_dataFile);
	if (fs.is_open() == false)
		throw ( std::runtime_error("Failed to open " + m_dataFile + ", provide a valid " + m_dataFile + " file with read permissions.") );
	if (fs.good() == false)
		throw ( std::runtime_error("The file " + m_dataFile + " is not in a good state.") );

	std::string	line;
	std::getline(fs, line);
	if (line != "date,exchange_rate")
		throw ( std::runtime_error("Invalid header in " + m_dataFile + ", expected: date,exchange_rate") );

	while (std::getline(fs, line))
		if (!line.empty() && line[0] != '\n')
			processEntry(splitCSVData(line), line);

	fs.close();
}


/* ************************************************************************** */
/* ************************************************************************** */


void	BitcoinExchange::processEntry(t_str_pair pair, std::string& line)
{
	if (pair.date.empty())
		throw ( std::runtime_error("Invalid input: empty date: <" + line + ">") );
	if (pair.price.empty())
		throw ( std::runtime_error("Invalid input: empty price: <" + line + ">") );
	
	m_price_table[strToTimePoint(pair.date, line).time_since_epoch().count()] = strToPrice(pair.price);
}

BitcoinExchange::t_str_pair		BitcoinExchange::splitCSVData(std::string& line)
{
	t_str_pair	pair;

	// delete all isspaces of line
	line.erase(std::remove_if(line.begin(), line.end(), [](char c){
		return (std::isspace(c));
	}), line.end());

	std::size_t	pos = line.find(',');
	if (pos == std::string::npos)
		throw ( std::runtime_error("Invalid input: delimiter missing: <" + line + ">") );

	pair.date = line.substr(0, pos);
	pair.price = line.substr(pos + 1);

	return (pair);
}

BitcoinExchange::t_time_point	BitcoinExchange::strToTimePoint(const std::string& str, const std::string& line)
{
	std::tm	time = {};
	std::stringstream is(str);

	validate_date(str, line);

	// convert str to tm
	is >> std::get_time(&time, "%Y-%m-%d");
	if (is.fail())
		throw ( std::runtime_error("Inavlid date format: expected YYYY-MM-DD: <" + line + ">") );

	// validate parsed Date
	char	buff[11] = {};
	std::strftime(buff, 11, "%Y-%m-%d", &time);
	if (buff != str)
		throw ( std::runtime_error("Failed to convert date to time: <" + str + ">") );

	// convert to time_t and return as time_point
	std::time_t	tt = std::mktime(&time);
	if (tt == -1)
		throw ( std::runtime_error("Failed to convert to time_t: <" + str + ">") );

	return (std::chrono::system_clock::from_time_t(tt));
}

uint64_t	BitcoinExchange::strToPrice(std::string& str)
{
	(void) str;
	return (0);
}

bool	BitcoinExchange::validate_date(const std::string& str, const std::string& line)
{
	if (str.length() != 10)
		throw ( std::runtime_error("Invalid length of date: <" + line + ">") );

	for (std::string::const_iterator it = str.cbegin(); it < str.cend(); ++it)
	{
		if (it == str.cbegin() + 4 || it == str.cbegin() + 7)
		{
			if (*it !=  '-')
				throw ( std::runtime_error("Inavlid date, requires dash between year, month and day: <" + line + ">") );
			++it;
		}
		if (std::isdigit(*it) == false)
			throw ( std::runtime_error("Invalid date, non digit found: <" + line + ">") );
	}

	std::stringstream	is;

	is = std::stringstream(str.substr(5, 2));	int month;	is >> month;
	if (month < 1 || month > 12)
		throw ( std::runtime_error("Invalid month in date: <" + line + ">") );

	is = std::stringstream(str.substr(8, 2));	int day;	is >> day;
	if (day < 1 || day > 31)
		throw ( std::runtime_error("Invalid day in date: <" + line + ">") );

	return (true);
}
