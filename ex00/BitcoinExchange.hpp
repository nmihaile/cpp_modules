/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:03 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/25 19:17:46 by nmihaile         ###   ########.fr       */
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

#define BTCEX_GRAY "\033[90m"
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
	typedef enum e_monetary_type
	{
		BTCEX_PRICE,
		BTCEX_AMOUNT
	}	t_monetary_type;
	
	class Input
	{
	public:
		std::string	line;
		std::string	date;
		std::string	price;
		std::size_t	line_nbr;
		const std::string	getLineNbr(void);
	};

	std::map<long long, uint64_t>	m_price_table;

	void			processEntry(BitcoinExchange::Input& input);
	void			evaluateEntry(BitcoinExchange::Input& input);
	void			splitEntry(BitcoinExchange::Input& input, char delimiter);

	std::ifstream	openFile(const std::string _file);
	t_time_point	strToTimePoint(BitcoinExchange::Input& input);
	uint64_t		strToPrice(BitcoinExchange::Input& input, t_monetary_type mtype);
	void			trimWhitespaces(std::string& str);

	bool			validate_date(BitcoinExchange::Input& input);
	bool			validate_price(BitcoinExchange::Input& input);
	bool			validate_amount(BitcoinExchange::Input& input);
};

#endif
