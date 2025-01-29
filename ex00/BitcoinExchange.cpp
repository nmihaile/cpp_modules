/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/29 11:45:58 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : m_dataFile(), m_price_table()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	:	m_dataFile(other.m_dataFile), m_price_table(other.m_price_table)
{
}

BitcoinExchange::~BitcoinExchange()
{
}


BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		m_dataFile = rhs.m_dataFile;
		m_price_table = rhs.m_price_table;
	}
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	BitcoinExchange::loadPriceTable(std::string _dataFile)
{
	m_dataFile = _dataFile;
	std::ifstream fs = openFile(_dataFile);

	BitcoinExchange::Input	input;
	input.line_nbr = 1;
	std::getline(fs, input.line);
	if (input.line != "date,exchange_rate")
		throw ( std::runtime_error("Invalid header in " + _dataFile + ", expected: date,exchange_rate" + input.lineNbrToStr()) );

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
	if (m_price_table.size() == 0)
	{
		std::cout << BTCEX_LIGHTRED << "No prices available, load a database first." << BTCEX_RESET << std::endl;
		return ;
	}

	std::ifstream fs = openFile(_inputFile);

	BitcoinExchange::Input	input;
	input.line_nbr = 1;
	std::getline(fs, input.line);
	if (input.line != "date | value")
		throw ( std::runtime_error("Invalid header in " + _inputFile + ", expected: date | value" + input.lineNbrToStr()) );

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
		throw ( std::runtime_error("Invalid input: empty date: <" + input.line + ">" + input.lineNbrToStr()) );
	if (input.monetary_str.empty())
		throw ( std::runtime_error("Invalid input: empty price: <" + input.line + ">" + input.lineNbrToStr()) );

	try
	{
		input.date = Date(input.date_str);
		input.value = MonetaryValue(input.monetary_str);
	}
	catch(const std::exception& e)
	{
		throw ( std::invalid_argument("Invalid input: " + std::string(e.what()) + " <" + input.line + ">" + input.lineNbrToStr()) );
	}

	m_price_table[input.date.toUnixTimestamp()] = input.value.getValueCents();
}

void	BitcoinExchange::evaluateEntry(BitcoinExchange::Input& input)
{
	try
	{
		MonetaryValue	amount;
		MonetaryValue	btcPrice;

		splitEntry(input, '|');
		if (input.date_str.empty())
			throw ( std::runtime_error("empty date: <" + input.line + ">") );
		if (input.monetary_str.empty())
			throw ( std::runtime_error("empty amount: <" + input.line + ">") );

		try
		{
			input.date = Date(input.date_str);
			input.value = MonetaryValue(input.monetary_str);
		}
		catch(const std::exception& e)
		{
			throw ( std::runtime_error(std::string(e.what()) + std::string(" <") + input.line + ">") );
		}
		
		amount = MonetaryValue(input.value.getValueCents());
		if (amount.getValueCents() > 1000 * 100)
			throw ( std::runtime_error("amount greater than 1000: <" + input.line + ">") );


		std::map<std::time_t, uint64_t>::iterator it = m_price_table.upper_bound(input.date.toUnixTimestamp());
		if (it == m_price_table.begin())
		{
			std::cout	<< BTCEX_LIGHTRED << "Invalid entry: " << BTCEX_RESET
						<< BTCEX_GRAY << "date is earlier than the first date loaded from " << m_dataFile << " <" << input.line << "> "
						<< BTCEX_LIGHTRED << "line: " << BTCEX_LIGHTCYAN << input.line_nbr << std::endl;
			return ;
		}
		btcPrice = MonetaryValue((*(--it)).second);
		
		MonetaryValue	btcAmount;
		btcAmount = amount * btcPrice;

		std::cout	<< BTCEX_LIGHTGREEN << input.date.toString() << BTCEX_GREEN
					<< " => " << BTCEX_RESET << std::setw(10) << input.monetary_str
					<< BTCEX_GRAY << " = " << BTCEX_LIGHTCYAN << btcAmount.getValueStr()
					<< BTCEX_RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::string e_str(e.what());
		if (size_t start = e_str.find("Invalid input: ") != std::string::npos)
			e_str.erase(e_str.begin() + start - 1, e_str.begin() + start + 14);
		if (e_str.find_first_of('\n') != std::string::npos)
			e_str.erase(e_str.begin() + e_str.find_first_of('\n'), e_str.end());
		
		std::cout	<< BTCEX_LIGHTRED << "Invalid entry: " << BTCEX_RESET
					<< BTCEX_GRAY << e_str << " "
					<< BTCEX_LIGHTRED << "line: " << BTCEX_LIGHTCYAN << input.line_nbr << std::endl;
		return ;
	}
}

void	BitcoinExchange::splitEntry(BitcoinExchange::Input& input, char delimiter)
{
	std::size_t	pos = input.line.find(delimiter);
	if (pos == std::string::npos)
		throw ( std::runtime_error("Invalid input: delimiter missing: <" + input.line + ">" + input.lineNbrToStr()) );

	input.date_str = input.line.substr(0, pos);
	input.monetary_str = input.line.substr(pos + 1);

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

/* ************************************************************************** */
/* ************************************************************************** */

const std::string	BitcoinExchange::Input::lineNbrToStr(void)
{
	return ( std::string("\n") + "(line: " + BTCEX_LIGHTCYAN + std::to_string(line_nbr) + BTCEX_LIGHTRED + ")" );
}
