/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:41:11 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/30 17:04:58 by nmihaile         ###   ########.fr       */
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

void	print_test_result(void)
{
	print_test_result("", "");
}


std::string	captureStdout(std::string expression)
{
	std::stringstream	buff;
	std::streambuf*		obuff = std::cout.rdbuf( buff.rdbuf() );

	try
	{
		RPN rpn;
		std::cout << rpn.evaluate(expression);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout.rdbuf(obuff);
	return (buff.str());
}

void	test(std::string expression, std::string expected)
{
	test_count(true);

	std::cout	<< LIGHTCYAN << "[" << std::setw(2) << std::setfill('0') << std::right << test_count(false) << "] " << RESET
				<< std::setw(45) << std::setfill(' ') << std::left << expression << GRAY << " -> " << RESET  << std::flush;

	std::string	result = captureStdout(expression);

	if (result == expected)
	{
		test_passed(true);
		std::cout << LIGHTGREEN << "[OK] " << RESET << std::endl;
		return ;
	}

	print_test_result(result, expected);
	exit(1);
}
