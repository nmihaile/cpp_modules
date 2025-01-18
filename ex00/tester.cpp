/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:35:08 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/18 12:20:53 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

size_t	test_count(bool do_count)
{
	static size_t	count;
	if (do_count)
		++count;
	return (count);
}

size_t	test_passed(bool do_count)
{
	static size_t	count;
	if (do_count)
		++count;
	return (count);
}

std::string	replace_underscores(std::string str)
{
	for (std::string::iterator it = str.begin(); it < str.end(); ++it)
		if (*it == '_')
			*it = ' ';
	return (str);
}

void	print_test_result(std::string msg, std::string expected)
{
	if (test_passed(false) == test_count(false))
	{
		std::cout << std::endl;
		std::cout << "  🎉🥳 All " << std::setw(2) << test_count(false) <<" tests passed! 🥳🎉" << std::endl;
		std::cout << LIGHTGREEN << "══════════════════════════════════" << RESET << std::endl;
	}
	else
	{
		std::cout << LIGHTRED << "[KO]\n" << RESET << std::endl;
		std::cout << LIGHTCYAN		<< "output  : [" <<  RESET << msg << LIGHTCYAN << "]" << RESET << std::endl;
		if (!expected.empty())
			std::cout << LIGHTCYAN	<< "expected: [" <<  RESET << expected << LIGHTCYAN << "]" << RESET << std::endl;

		std::cout << "  ❌ " << LIGHTRED << "Failed at test: " << LIGHTCYAN << "[" << test_count(false) << "]" << std::endl;
		std::cout << RESET << "     please investigate and debug accordingly…" << std::endl;
		std::cout << LIGHTRED << "══════════════════════════════════════════════════" << RESET << std::endl;

		exit(1);
	}
}

void	test(void (*test_func)(void), std::string expected, const std::string& funcName)
{
	test_count(true);

	std::cout	<< LIGHTCYAN << "[" << std::setw(2) << std::setfill('0') << std::right << test_count(false) << "] " << RESET
				<< std::setw(45) << std::setfill(' ') << std::left << replace_underscores(funcName) << " -> "  << std::flush;

	std::stringstream	buff;
	std::streambuf*		obuff = std::cout.rdbuf( buff.rdbuf() );

	try
	{
		test_func();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	std::cout.rdbuf(obuff);
	if (buff.str() == expected)
	{
		test_passed(true);
		std::cout << LIGHTGREEN << "[OK] " << RESET << std::endl;
		return ;
	}

	print_test_result(buff.str(), expected);
	exit(1);
}
