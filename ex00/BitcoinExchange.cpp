/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/25 17:36:27 by nmihaile         ###   ########.fr       */
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
	std::ifstream fs = openFile(_dataFile);

	BitcoinExchange::Input	input;
	input.line_nbr = 1;
	std::getline(fs, input.line);
	if (input.line != "date,exchange_rate")
		throw ( std::runtime_error("Invalid header in " + _dataFile + ", expected: date,exchange_rate" + input.getLineNbr()) );

	while (std::getline(fs, input.line))
	{
		++input.line_nbr;
		if (!input.line.empty())
			processEntry(input);
	}

	fs.close();
}

void	BitcoinExchange::evaluateInputFile(std::string _inputFile)
{
	std::ifstream fs = openFile(_inputFile);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	BitcoinExchange::processEntry(BitcoinExchange::Input& input)
{
	splitCSVData(input);

	if (input.date.empty())
		throw ( std::runtime_error("Invalid input: empty date: <" + input.line + ">" + input.getLineNbr()) );
	if (input.price.empty())
		throw ( std::runtime_error("Invalid input: empty price: <" + input.line + ">" + input.getLineNbr()) );
	
	m_price_table[strToTimePoint(input).time_since_epoch().count()] = strToPrice(input);
}

void	BitcoinExchange::splitCSVData(BitcoinExchange::Input& input)
{

	std::size_t	pos = input.line.find(',');
	if (pos == std::string::npos)
		throw ( std::runtime_error("Invalid input: delimiter missing: <" + input.line + ">" + input.getLineNbr()) );

	input.date = input.line.substr(0, pos);
	input.price = input.line.substr(pos + 1);

	// delete leadind and tailing whitespaces of input.line
	trimWhitespaces(input.date);
	trimWhitespaces(input.price);
}

std::ifstream	BitcoinExchange::openFile(const std::string _file)
{
	std::ifstream	fs;

	fs.open(_file);
	if (fs.is_open() == false)
		throw ( std::runtime_error("Failed to open " + _file + ", provide a valid file " + _file + " with read permissions.") );
	if (fs.good() == false)
		throw ( std::runtime_error("The file " + _file + " is not in a good state.") );

	return (fs);
}

BitcoinExchange::t_time_point	BitcoinExchange::strToTimePoint(BitcoinExchange::Input& input)
{
	std::tm	time = {};

	validate_date(input);

	// convert str to tm
	std::stringstream is(input.date);
	is >> std::get_time(&time, "%Y-%m-%d");
	if (is.fail())
		throw ( std::runtime_error("Inavlid date format: expected YYYY-MM-DD: <" + input.line + ">" + input.getLineNbr()) );

	// validate parsed Date
	char	buff[11] = {};
	std::strftime(buff, 11, "%Y-%m-%d", &time);
	if (buff != input.date)
		throw ( std::runtime_error("Failed to convert date to time: <" + input.date + ">" + input.getLineNbr()) );

	// convert to time_t and return as time_point
	std::time_t	tt = std::mktime(&time);
	if (tt == -1)
		throw ( std::runtime_error("Failed to convert to time_t: <" + input.date + ">" + input.getLineNbr()) );

	return (std::chrono::system_clock::from_time_t(tt));
}

uint64_t	BitcoinExchange::strToPrice(BitcoinExchange::Input& input)
{
	validate_price(input);

	std::stringstream	ss(input.price);
	float				fvalue;

	ss >> fvalue;
	if (ss.fail())
		throw( std::runtime_error("Failed to convert price: <" + input.price + ">" + input.getLineNbr()) );
	
	uint64_t	value;
	value = static_cast<uint64_t>(fvalue * 100);

	return (value);
}

void	BitcoinExchange::trimWhitespaces(std::string& str)
{
	std::string::iterator	start	= str.begin();
	std::string::iterator	end		= str.end();

	while (start != end && std::isspace(*start))
		++start;
	while (end != start && std::isspace(*(end - 1)))
		--end;
	
	str = std::string(start, end);
}

bool	BitcoinExchange::validate_date(BitcoinExchange::Input& input)
{
	if (input.date.length() != 10)
		throw ( std::runtime_error("Invalid length of date: <" + input.line + ">" + input.getLineNbr()) );

	for (std::string::iterator it = input.date.begin(); it < input.date.end(); ++it)
	{
		if (it == input.date.begin() + 4 || it == input.date.begin() + 7)
		{
			if (*it !=  '-')
				throw ( std::runtime_error("Inavlid date, requires dash between year, month and day: <" + input.line + ">" + input.getLineNbr()) );
			++it;
		}
		if (std::isdigit(*it) == false)
			throw ( std::runtime_error("Invalid date, non digit found: <" + input.line + ">" + input.getLineNbr()) );
	}

	std::stringstream	is;

	is = std::stringstream(input.date.substr(5, 2));	int month;	is >> month;
	if (month < 1 || month > 12)
		throw ( std::runtime_error("Invalid month in date: <" + input.line + ">" + input.getLineNbr()) );

	is = std::stringstream(input.date.substr(8, 2));	int day;	is >> day;
	if (day < 1 || day > 31)
		throw ( std::runtime_error("Invalid day in date: <" + input.line + ">" + input.getLineNbr()) );

	return (true);
}

// The subject informs: either a float or a positive integer
// for the input_db: between 0 and 1000
bool	BitcoinExchange::validate_price(BitcoinExchange::Input& input)
{
	for (std::string::iterator it = input.price.begin(); it < input.price.end(); ++it)
		if (!std::isdigit(*it) && !(*it == '.'))
			throw ( std::runtime_error("Invalid price: <" + input.line + ">" + input.getLineNbr()) );

	return (true);
}

/* ************************************************************************** */
/* ************************************************************************** */

const std::string	BitcoinExchange::Input::getLineNbr(void)
{
	return ( std::string("\n") + "(line: " + std::to_string(line_nbr) + ")" );
}
