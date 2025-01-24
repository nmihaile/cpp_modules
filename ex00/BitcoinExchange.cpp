/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/24 15:41:36 by nmihaile         ###   ########.fr       */
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


void	BitcoinExchange::loadPriceTable(void)
{
	std::ifstream	fs;

	fs.open("data.csv");
	if (fs.is_open() == false)
		throw ( std::runtime_error("Failed to open price data, provide a valid data.csv file.") );
	if (fs.good() == false)
		throw ( std::runtime_error("The file data.csv is not in a good state.") );

	std::string	line;
	std::getline(fs, line);
	if (line != "date,exchange_rate")
		throw ( std::runtime_error("Invalid header in data.csv, expected: date,exchange_rate") );

	while (std::getline(fs, line))
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
	
	price_table[strToTimePoint(pair.date, line).time_since_epoch().count()] = strToPrice(pair.price);
}

BitcoinExchange::t_str_pair		BitcoinExchange::splitCSVData(std::string& str)
{
	t_str_pair	pair;

	std::size_t	pos = str.find(',');
	if (pos == std::string::npos)
		throw ( std::runtime_error("Invalid input: dilimiter missing: <" + str + ">") );

	pair.date = str.substr(0, pos);
	pair.price = str.substr(pos + 1);

	return (pair);
}

BitcoinExchange::t_time_point	BitcoinExchange::strToTimePoint(std::string& str, std::string& line)
{
	std::tm	time = {};
	std::stringstream is(str);

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
