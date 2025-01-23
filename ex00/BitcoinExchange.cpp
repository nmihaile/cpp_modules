/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:55:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/23 12:36:16 by nmihaile         ###   ########.fr       */
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
		// TODO: handle dailyBtcPrices 
	}
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	BitcoinExchange::loadPriceTable(void)
{
	std::fstream	fs;

	fs.open("data.csv");
	if (fs.is_open() == false)
		throw ( std::runtime_error("Failed to open price data, provide a valid data.csv file."));

	

	fs.close();
}

