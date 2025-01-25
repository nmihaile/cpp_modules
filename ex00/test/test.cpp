/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:17 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/25 17:02:39 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include "../BitcoinExchange.hpp"

void	test_instantiating_btcEx(void)
{
	BitcoinExchange btcEx;
	btcEx.loadPriceTable("data.csv");
}

void	test_open_data_csv_missing_file(void)
{
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("missing_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
}

void	test_open_data_csv_without_permissions(void)
{
	system("chmod 000 data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("chmod 644 data.csv");
}

void	test_inavlid_header_of_data_csv(void)
{
	system("echo \"2009-01-02,0\n2009-01-05,0\n\" > header_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("header_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f header_data.csv");
}

void	test_missing_delimiter(void)
{
	system("echo \"date,exchange_rate\n2009-01-021000\n2009-01-05,0\n\" > delimiter_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("delimiter_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f delimiter_data.csv");
}

void	test_empty_date(void)
{
	system("echo \"date,exchange_rate\n,1000\n2009-01-05,0\n\" > empty_date_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("empty_date_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f empty_date_data.csv");
}

void	test_empty_price(void)
{
	system("echo \"date,exchange_rate\n2009-01-04,\n2009-01-05,0\n\" > empty_price_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("empty_price_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f empty_price_data.csv");
}

void	test_invalid_date_format_01_ordering(void)
{
	system("echo \"date,exchange_rate\n2009-30-01,500\n2009-01-05,0\n\" > format01_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("format01_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f format01_data.csv");
}

void	test_invalid_date_format_02_short_year(void)
{
	system("echo \"date,exchange_rate\n09-01-01,500\n2009-01-05,0\n\" > format02_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("format02_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f format02_data.csv");
}

void	test_invalid_date_format_03_non_digit(void)
{
	system("echo \"date,exchange_rate\n2009-0a-01,500\n2009-01-05,0\n\" > format03_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("format03_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f format03_data.csv");
}

void	test_invalid_date_format_04_no_dashes(void)
{
	system("echo \"date,exchange_rate\n2009-01_01,500\n2009-01-05,0\n\" > format04_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("format04_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f format04_data.csv");
}

void	test_invalid_date_day_to_high(void)
{
	system("echo \"date,exchange_rate\n2009-01-32,500\n2009-01-05,0\n\" > day_high_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("day_high_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f day_high_data.csv");
}

void	test_invalid_date_month_to_high(void)
{
	system("echo \"date,exchange_rate\n2009-13-01,500\n2009-01-05,0\n\" > month_high_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("month_high_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f month_high_data.csv");
}

void	test_invalid_date_day_to_low(void)
{
	system("echo \"date,exchange_rate\n2009-12-00,500\n2009-01-05,0\n\" > day_low_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("day_low_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f day_low_data.csv");
}

void	test_invalid_date_month_to_low(void)
{
	system("echo \"date,exchange_rate\n2009-00-01,500\n2009-01-05,0\n\" > month_low_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("month_low_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f month_low_data.csv");
}

void	test_empty_lines_in_data_csv(void)
{
	system("echo \"date,exchange_rate\n\n2009-01-01,500\n\n2009-01-02,600\n\n\n\n\n\n\n2009-01-03,700\n\" > empty_lines_in_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("empty_lines_in_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f empty_lines_in_data.csv");
}

void	test_whitespaces_in_data_csv_01(void)
{
	system("echo \"date,exchange_rate\n\t\v\f\r 2009-01-01 \t\v\f\r, \t\v\f\r500 \t\v\f\r\n2009-01-02,600\n2009-01-03,700\n\" > whitespaces_in_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("whitespaces_in_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f whitespaces_in_data.csv");
}

void	test_whitespaces_in_data_csv_02(void)
{
	system("echo \"date,exchange_rate\n2 0\t0\v9\f-\r0 1-0 1 ,500\n2009-01-02,6002009-01-03,700\n\" > whitespaces_in_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("whitespaces_in_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f whitespaces_in_data.csv");
}

void	test_whitespaces_in_data_csv_03(void)
{
	system("echo \"date,exchange_rate\n2009-01-01,500\n2009-01-02,60 \t\v\f\r0\n2009-01-03,700\n\" > whitespaces_in_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("whitespaces_in_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f whitespaces_in_data.csv");
}

void	test_invalid_price_characters_01(void)
{
	system("echo \"date,exchange_rate\n2009-01-01,500\n2009-01-02,6a00\n2009-01-03,700\n\" > invalid_price_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("invalid_price_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f invalid_price_data.csv");
}

void	test_invalid_price_characters_02(void)
{
	system("echo \"date,exchange_rate\n2009-01-01,500\n2009-01-02,60.1k5\n2009-01-03,700\n\" > invalid_price_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("invalid_price_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f invalid_price_data.csv");
}

void	test_valid_price_characters(void)
{
	system("echo \"date,exchange_rate\n2009-01-01,500\n2009-01-02,123.45\n2009-01-03,700\n\" > invalid_price_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("invalid_price_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f invalid_price_data.csv");
}

int	main(void)
{

	TEST(test_instantiating_btcEx, "");
	TEST(test_open_data_csv_missing_file, "Failed to open missing_data.csv, provide a valid missing_data.csv file with read permissions.\n");
	TEST(test_open_data_csv_without_permissions, "Failed to open data.csv, provide a valid data.csv file with read permissions.\n");
	TEST(test_inavlid_header_of_data_csv, "Invalid header in header_data.csv, expected: date,exchange_rate\n(line: 1)\n");
	TEST(test_missing_delimiter, "Invalid input: delimiter missing: <2009-01-021000>\n(line: 2)\n");
	TEST(test_empty_date, "Invalid input: empty date: <,1000>\n(line: 2)\n");
	TEST(test_empty_price, "Invalid input: empty price: <2009-01-04,>\n(line: 2)\n");
	TEST(test_invalid_date_format_01_ordering, "Invalid month in date: <2009-30-01,500>\n(line: 2)\n");
	TEST(test_invalid_date_format_02_short_year, "Invalid length of date: <09-01-01,500>\n(line: 2)\n");
	TEST(test_invalid_date_format_03_non_digit, "Invalid date, non digit found: <2009-0a-01,500>\n(line: 2)\n");
	TEST(test_invalid_date_format_04_no_dashes, "Inavlid date, requires dash between year, month and day: <2009-01_01,500>\n(line: 2)\n");
	TEST(test_invalid_date_day_to_high, "Invalid day in date: <2009-01-32,500>\n(line: 2)\n");
	TEST(test_invalid_date_month_to_high, "Invalid month in date: <2009-13-01,500>\n(line: 2)\n");
	TEST(test_invalid_date_day_to_low, "Invalid day in date: <2009-12-00,500>\n(line: 2)\n");
	TEST(test_invalid_date_month_to_low, "Invalid month in date: <2009-00-01,500>\n(line: 2)\n");
	TEST(test_empty_lines_in_data_csv, "");
	TEST(test_whitespaces_in_data_csv_01, "");
	TEST(test_whitespaces_in_data_csv_02, "Invalid length of date: <2 0\t0\v9\f-\r0 1-0 1 ,500>\n(line: 2)\n");
	TEST(test_whitespaces_in_data_csv_03, "Invalid price: <2009-01-02,60 \t\v\f\r0>\n(line: 3)\n");
	TEST(test_invalid_price_characters_01, "Invalid price: <2009-01-02,6a00>\n(line: 3)\n");
	TEST(test_invalid_price_characters_02, "Invalid price: <2009-01-02,60.1k5>\n(line: 3)\n");
	TEST(test_valid_price_characters, "");

	print_test_result();

	return (0);
}
