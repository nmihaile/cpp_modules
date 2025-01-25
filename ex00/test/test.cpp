/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:17 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/25 12:36:18 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include "../BitcoinExchange.hpp"

void	test_instantiating_btcEx(void)
{
	BitcoinExchange btcEx;
	btcEx.loadPriceTable();
}

void	test_open_data_csv_missing_file(void)
{
	system("mv data.csv bdata.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("mv bdata.csv data.csv");
}

void	test_open_data_csv_without_permissions(void)
{
	system("chmod 000 data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("chmod 644 data.csv");
}

void	test_inavlid_header_of_data_csv(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"2009-01-02,0\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_missing_delimiter(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n2009-01-021000\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_empty_date(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n,1000\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_empty_price(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n2009-01-04,\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_invalid_date_format_01_ordering(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n2009-30-01,500\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_invalid_date_format_02_short_year(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n09-01-01,500\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_invalid_date_format_03_non_digit(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n2009-0a-01,500\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_invalid_date_format_04_no_dashes(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n2009-01_01,500\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_invalid_date_day_to_high(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n2009-01-32,500\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_invalid_date_month_to_high(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n2009-13-01,500\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_invalid_date_day_to_low(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n2009-12-00,500\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

void	test_invalid_date_month_to_low(void)
{
	system("mv data.csv bdata.csv");
	system("echo \"date,exchange_rate\n2009-00-01,500\n2009-01-05,0\n\" > data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable();
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f data.csv");
	system("mv bdata.csv data.csv");
}

int	main(void)
{

	TEST(test_instantiating_btcEx, "");
	TEST(test_open_data_csv_missing_file, "Failed to open data.csv, provide a valid data.csv file with read permissions.\n");
	TEST(test_open_data_csv_without_permissions, "Failed to open data.csv, provide a valid data.csv file with read permissions.\n");
	TEST(test_inavlid_header_of_data_csv, "Invalid header in data.csv, expected: date,exchange_rate\n");
	TEST(test_missing_delimiter, "Invalid input: delimiter missing: <2009-01-021000>\n");
	TEST(test_empty_date, "Invalid input: empty date: <,1000>\n");
	TEST(test_empty_price, "Invalid input: empty price: <2009-01-04,>\n");
	TEST(test_invalid_date_format_01_ordering, "Invalid month in date: <2009-30-01,500>\n");
	TEST(test_invalid_date_format_02_short_year, "Invalid length of date: <09-01-01,500>\n");
	TEST(test_invalid_date_format_03_non_digit, "Invalid date, non digit found: <2009-0a-01,500>\n");
	TEST(test_invalid_date_format_04_no_dashes, "Inavlid date, requires dash between year, month and day: <2009-01_01,500>\n");
	TEST(test_invalid_date_day_to_high, "Invalid day in date: <2009-01-32,500>\n");
	TEST(test_invalid_date_month_to_high, "Invalid month in date: <2009-13-01,500>\n");
	TEST(test_invalid_date_day_to_low, "Invalid day in date: <2009-12-00,500>\n");
	TEST(test_invalid_date_month_to_low, "Invalid month in date: <2009-00-01,500>\n");

	print_test_result();

	return (0);
}
