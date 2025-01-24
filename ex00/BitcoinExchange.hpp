/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:03 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/24 13:23:34 by nmihaile         ###   ########.fr       */
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

#include <iostream>

class BitcoinExchange
{
public:
	typedef std::chrono::system_clock::time_point t_time_point;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	void	loadPriceTable(void);

private:
	typedef struct s_str_pair
	{
		std::string	date;
		std::string	price;
	} t_str_pair;
	std::map<long long, uint64_t>	price_table;

	void			processEntry(t_str_pair pair, std::string& line);
	t_str_pair		splitCSVData(std::string& str);
	t_time_point	strToTimePoint(std::string& str, std::string& line);
	uint64_t		strToPrice(std::string& str);
};

#endif
