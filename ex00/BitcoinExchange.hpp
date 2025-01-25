/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:03 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/25 15:23:51 by nmihaile         ###   ########.fr       */
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

class BitcoinExchange
{
public:
	typedef std::chrono::system_clock::time_point t_time_point;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	void	loadPriceTable(std::string _dataFile);

private:
	class Input
	{
	public:
		std::string	line;
		std::string	date;
		std::string	price;
		std::size_t	line_nbr;
		const std::string	getLineNbr(void);
	};

	std::string						m_dataFile;
	std::map<long long, uint64_t>	m_price_table;

	void			processEntry(BitcoinExchange::Input& input);
	void			splitCSVData(BitcoinExchange::Input& input);

	t_time_point	strToTimePoint(BitcoinExchange::Input& input);
	uint64_t		strToPrice(BitcoinExchange::Input& input);
	void			trimWhitespaces(std::string& str);

	bool			validate_date(BitcoinExchange::Input& input);
	bool			validate_price(BitcoinExchange::Input& input);
};

#endif
