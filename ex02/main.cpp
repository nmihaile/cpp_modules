/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:35:02 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/14 12:08:25 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define GREEN			"\033[32m"
#define BLUE			"\033[34m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTYELLOW		"\033[93m"
#define LIGHTBLUE		"\033[94m"
#define LIGHTMAGENTA	"\033[95m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

#define SUCCESS true
#define FAIL false
#define SuccessMSG std::string(GREEN) + std::string("Success, no exception cought.") + std::string(RESET)
#define defaultExceptionMSG std::string("Default exception caught. Please debug further.")
#define ExceptionPrefix std::string(LIGHTRED) + std::string("Exception cought: ") + std::string(RESET)

void	printFunc(const char *func) { std::cout << LIGHTCYAN << "--[ " << func << " ]--" << RESET << std::endl; }
int		total_count(bool count) { static int c; if (count == true) c++; return (c); }
int		test_passed(bool count) { static int c; if (count == true) c++; return (c); }
void	nl(void) { std::cout << std::endl; }
void	Succeded_or_Failed(bool expected, bool result, std::string msg)
{
	total_count(true);
	if (expected == result)
	{
		test_passed(true);
		std::cout << LIGHTGREEN << "  [OK] " << RESET;
	}
	else
		std::cout << LIGHTRED << "  [KO] " << RESET;
	std::cout << msg << std::endl; // << std::endl
}

void	test(void f(void), bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	try { f(); }
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (std::string& e)		{ msg = ExceptionPrefix + e;					result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

/* ************************************************************************** */
/* ******************************  TESTS  *********************************** */
/* ************************************************************************** */

int	main(void)
{
	
	return (0);
}
