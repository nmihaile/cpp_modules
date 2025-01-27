/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/27 17:17:12 by nmihaile         ###   ########.fr       */
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
		// TODO: 
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

	BitcoinExchange::Input	input;
	input.line_nbr = 1;
	std::getline(fs, input.line);
	if (input.line != "date | value")
		throw ( std::runtime_error("Invalid header in " + _inputFile + ", expected: date,exchange_rate" + input.getLineNbr()) );

	while (std::getline(fs, input.line))
	{
		++input.line_nbr;
		if (!input.line.empty())
			evaluateEntry(input);
	}

	fs.close();
}


/* ************************************************************************** */
/* ************************************************************************** */


void	BitcoinExchange::processEntry(BitcoinExchange::Input& input)
{
	splitEntry(input, ',');

	if (input.date_str.empty())
		throw ( std::runtime_error("Invalid input: empty date: <" + input.line + ">" + input.getLineNbr()) );
	if (input.monetary_str.empty())
		throw ( std::runtime_error("Invalid input: empty price: <" + input.line + ">" + input.getLineNbr()) );
	
	try
	{
		input.date = Date(input.date_str);
	}
	catch(const std::exception& e)
	{
		throw ( std::invalid_argument("Invalid input: " + std::string(e.what()) + " <" + input.line + ">" + input.getLineNbr()) );
	}

	m_price_table[input.date.toUnixTimestamp()] = strToPrice(input, BTCEX_PRICE);
}

void	BitcoinExchange::evaluateEntry(BitcoinExchange::Input& input)
{
	// time_t		timestamp;
	uint64_t	amount;

	try
	{
		splitEntry(input, '|');
		if (input.date_str.empty())
			throw ( std::runtime_error("empty date: <" + input.line + ">") );
		if (input.monetary_str.empty())
			throw ( std::runtime_error("empty amount: <" + input.line + ">") );

		// timestamp	= strToUnixTimestamp(input);
		amount		= strToPrice(input, BTCEX_AMOUNT);

		if (amount > 1000 * 100)
			throw ( std::runtime_error("amount greater than 1000: <" + input.line + ">") );

	}
	catch(const std::exception& e)
	{
		std::string e_str(e.what());
		if (e_str.find_first_of('\n') != std::string::npos)
			e_str.erase(e_str.begin() + e_str.find_first_of('\n'), e_str.end());
		if (size_t start = e_str.find("Invalid input: ") != std::string::npos)
			e_str.erase(e_str.begin() + start - 1, e_str.begin() + start + 14);
		
		std::cout	<< BTCEX_LIGHTRED << "Invalid entry " << BTCEX_RESET
					<< BTCEX_GRAY << e_str << " "
					<< BTCEX_LIGHTRED << "at line: " << BTCEX_LIGHTCYAN << input.line_nbr << '\n';
		return ;
	}

	std::cout << BTCEX_LIGHTGREEN << "good line" << BTCEX_RESET << std::endl;
}

void	BitcoinExchange::splitEntry(BitcoinExchange::Input& input, char delimiter)
{
	std::size_t	pos = input.line.find(delimiter);
	if (pos == std::string::npos)
		throw ( std::runtime_error("Invalid input: delimiter missing: <" + input.line + ">" + input.getLineNbr()) );

	input.date_str = input.line.substr(0, pos);
	input.monetary_str = input.line.substr(pos + 1);

	// delete leadind and tailing whitespaces of input.line
	trimWhitespaces(input.date_str);
	trimWhitespaces(input.monetary_str);
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

uint64_t	BitcoinExchange::strToPrice(BitcoinExchange::Input& input, t_monetary_type mtype)
{
	if (mtype == BTCEX_PRICE)
		validate_price(input);
	else
		validate_amount(input);

	std::stringstream	ss(input.monetary_str);
	float				fvalue;

	ss >> fvalue;
	if (ss.fail())
		throw( std::runtime_error("Failed to convert price: <" + input.monetary_str + ">" + input.getLineNbr()) );
	
	uint64_t	value;
	value = static_cast<uint64_t>(fvalue * 100.0f);

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

// The subject informs: either a float or a positive integer
// for the input_db: between 0 and 1000
bool	BitcoinExchange::validate_price(BitcoinExchange::Input& input)
{
	for (std::string::iterator it = input.monetary_str.begin(); it < input.monetary_str.end(); ++it)
		if (!std::isdigit(*it) && !(*it == '.'))
			throw ( std::runtime_error("Invalid price: <" + input.line + ">" + input.getLineNbr()) );

	return (true);
}

bool	BitcoinExchange::validate_amount(BitcoinExchange::Input& input)
{
	if (input.monetary_str[0] == '-')
		throw ( std::runtime_error("Invalid input: negative amount: <" + input.line + ">" + input.getLineNbr()) );

	for (std::string::iterator it = input.monetary_str.begin(); it < input.monetary_str.end(); ++it)
		if (!std::isdigit(*it) && !(*it == '.'))
			throw ( std::runtime_error("Invalid amount: <" + input.line + ">" + input.getLineNbr()) );

	return (true);
}

/* ************************************************************************** */
/* ************************************************************************** */

const std::string	BitcoinExchange::Input::getLineNbr(void)
{
	return ( std::string("\n") + "(line: " + std::to_string(line_nbr) + ")" );
}
