/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:17 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/28 15:16:02 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "tester.hpp"
#include "../BitcoinExchange.hpp"
#include "../Date.hpp"

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

void	test_invalid_MonetaryValue_characters_01(void)
{
	system("echo \"date,exchange_rate\n2009-01-01,500\n2009-01-02,6a00\n2009-01-03,700\n\" > invalid_monetary_value_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("invalid_monetary_value_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f invalid_monetary_value_data.csv");
}

void	test_invalid_MonetaryValue_characters_02(void)
{
	system("echo \"date,exchange_rate\n2009-01-01,500\n2009-01-02,60.1k5\n2009-01-03,700\n\" > invalid_monetary_value_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("invalid_monetary_value_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f invalid_monetary_value_data.csv");
}

void	test_MonetaryValue_multiple_decimal_points(void)
{
	system("echo \"date,exchange_rate\n2009-01-01,500\n2009-01-02,123.45.678\n2009-01-03,700\n\" > invalid_monetary_value_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("invalid_monetary_value_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f invalid_monetary_value_data.csv");
}

void	test_valid_MonetaryValue_characters(void)
{
	system("echo \"date,exchange_rate\n2009-01-01,500\n2009-01-02,123.45\n2009-01-03,700\n\" > invalid_monetary_value_data.csv");
	try
	{
		BitcoinExchange btcEx;
		btcEx.loadPriceTable("invalid_monetary_value_data.csv");
	}
	catch(const std::exception& e) { std::cout << e.what() << '\n'; }	
	system("rm -f invalid_monetary_value_data.csv");
}

void	test_Date_class_leap_years(void)
{
	static const int leapyears[] = {
		1804, 1808, 1812, 1816, 1820, 1824, 1828, 1832, 1836, 1840, 1844, 1848, 1852, 1856, 1860, 1864, 1868, 1872, 1876, 1880,
		1884, 1888, 1892, 1896, 1904, 1908, 1912, 1916, 1920, 1924, 1928, 1932, 1936, 1940, 1944, 1948, 1952, 1956, 1960, 1964,
		1968, 1972, 1976, 1980, 1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016, 2020, 2024, 2028, 2032, 2036, 2040, 2044,
		2048, 2052, 2056, 2060, 2064, 2068, 2072, 2076, 2080, 2084, 2088, 2092, 2096, 2104, 2108, 2112, 2116, 2120, 2124, 2128,
		2132, 2136, 2140, 2144, 2148, 2152, 2156, 2160, 2164, 2168, 2172, 2176, 2180, 2184, 2188, 2192, 2196, 2204, 2208, 2212,
		2216, 2220, 2224, 2228, 2232, 2236, 2240, 2244, 2248, 2252, 2256, 2260, 2264, 2268, 2272, 2276, 2280, 2284, 2288, 2292,
		2296, 2304, 2308, 2312, 2316, 2320, 2324, 2328, 2332, 2336, 2340, 2344, 2348, 2352, 2356, 2360, 2364, 2368, 2372, 2376,
		2380, 2384, 2388, 2392, 2396, 2400
	};

	for (std::size_t i = 0; i < sizeof(leapyears) / sizeof(leapyears[0]); ++i)
	{
		std::string	date_s = std::to_string(leapyears[i]) + "-01-01";
		Date		date(date_s);
		if (date.isLeapYear())
			std::cout << ".";
		else
		{
			std::cout << "WONG";
			return ;
		}
	}
}

int	main(void)
{

	TEST(test_instantiating_btcEx, "");
	TEST(test_open_data_csv_missing_file, "Failed to open missing_data.csv, provide a valid file missing_data.csv with read permissions.\n");
	TEST(test_open_data_csv_without_permissions, "Failed to open data.csv, provide a valid file data.csv with read permissions.\n");
	TEST(test_inavlid_header_of_data_csv, "Invalid header in header_data.csv, expected: date,exchange_rate\n(line: 1)\n");
	TEST(test_missing_delimiter, "Invalid input: delimiter missing: <2009-01-021000>\n(line: 2)\n");
	TEST(test_empty_date, "Invalid input: empty date: <,1000>\n(line: 2)\n");
	TEST(test_empty_price, "Invalid input: empty price: <2009-01-04,>\n(line: 2)\n");
	TEST(test_invalid_date_format_01_ordering, "Invalid input: month out of range 01-12 <2009-30-01,500>\n(line: 2)\n");
	TEST(test_invalid_date_format_02_short_year, "Invalid input: wrong length of date (expecet format YYYY-MM-DD) <09-01-01,500>\n(line: 2)\n");
	TEST(test_invalid_date_format_03_non_digit, "Invalid input: wrong delimiter in date <2009-0a-01,500>\n(line: 2)\n");
	TEST(test_invalid_date_format_04_no_dashes, "Invalid input: wrong delimiter in date <2009-01_01,500>\n(line: 2)\n");
	TEST(test_invalid_date_day_to_high, "Invalid input: day out of range 01-31 <2009-01-32,500>\n(line: 2)\n");
	TEST(test_invalid_date_month_to_high, "Invalid input: month out of range 01-12 <2009-13-01,500>\n(line: 2)\n");
	TEST(test_invalid_date_day_to_low, "Invalid input: day out of range 01-31 <2009-12-00,500>\n(line: 2)\n");
	TEST(test_invalid_date_month_to_low, "Invalid input: month out of range 01-12 <2009-00-01,500>\n(line: 2)\n");
	TEST(test_empty_lines_in_data_csv, "");
	TEST(test_whitespaces_in_data_csv_01, "");
	TEST(test_whitespaces_in_data_csv_02, "Invalid input: wrong length of date (expecet format YYYY-MM-DD) <2 0\t0\v9\f-\r0 1-0 1 ,500>\n(line: 2)\n");
	TEST(test_whitespaces_in_data_csv_03, "Invalid input: non monetary character detected, allowd [0..9|.] <2009-01-02,60 \t\v\f\r0>\n(line: 3)\n");
	TEST(test_invalid_MonetaryValue_characters_01, "Invalid input: non monetary character detected, allowd [0..9|.] <2009-01-02,6a00>\n(line: 3)\n");
	TEST(test_invalid_MonetaryValue_characters_02, "Invalid input: non monetary character detected, allowd [0..9|.] <2009-01-02,60.1k5>\n(line: 3)\n");
	TEST(test_MonetaryValue_multiple_decimal_points, "Invalid input: found multiple decimal points, only one allowed <2009-01-02,123.45.678>\n(line: 3)\n");
	TEST(test_valid_MonetaryValue_characters, "");
	TEST(test_Date_class_leap_years, "..................................................................................................................................................");

	print_test_result();

	return (0);
}
