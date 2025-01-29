/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:03 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/29 11:15:26 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <chrono>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iostream>
#include "Date.hpp"
#include "MonetaryValue.hpp"

#define BTCEX_GRAY "\033[90m"
#define BTCEX_GREEN "\033[32m"
#define BTCEX_LIGHTRED "\033[91m"
#define BTCEX_LIGHTGREEN "\033[92m"
#define BTCEX_LIGHTCYAN "\033[96m"
#define BTCEX_RESET "\033[0m"

class BitcoinExchange
{
public:
	typedef std::chrono::system_clock::time_point t_time_point;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	void	loadPriceTable(std::string _dataFile);
	void	evaluateInputFile(std::string _inputFile);

private:
	class Input
	{
	public:
		std::string	line;
		std::string	date_str;
		std::string	monetary_str;
		std::size_t	line_nbr;

		Date			date;
		MonetaryValue	value;

		const std::string	lineNbrToStr(void);
	};

	std::string						m_dataFile;
	std::map<std::time_t, uint64_t>	m_price_table;

	void			processEntry(BitcoinExchange::Input& input);
	void			evaluateEntry(BitcoinExchange::Input& input);
	void			splitEntry(BitcoinExchange::Input& input, char delimiter);

	std::ifstream	openFile(const std::string _file);
	void			trimWhitespaces(std::string& str);
};

#endif
