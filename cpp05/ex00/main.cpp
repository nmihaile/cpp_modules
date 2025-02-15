/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:51:26 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/17 19:06:46 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTYELLOW		"\033[93m"
#define BLUE			"\033[34m"
#define LIGHTBLUE		"\033[94m"
#define LIGHTMAGENTA	"\033[95m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

void	TestGradeToHigh()
{
	std::cout << LIGHTCYAN << "--[ " << __func__ << " ]--" << std::endl;
	try
	{
		Bureaucrat B("Alice", 0);
		std::cout << LIGHTYELLOW << "THIS SHOULD NOT BE SEEN: " << B;
	}
	catch(std::exception& e)
	{
		std::cout << LIGHTRED << "Exception cought: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	TestGradeToLow()
{
	std::cout << LIGHTCYAN << "--[ " << __func__ << " ]--" << std::endl;
	try
	{
		Bureaucrat B("Bob", 160);
		std::cout << LIGHTYELLOW << "THIS SHOULD NOT BE SEEN: " << B;
	}
	catch(std::exception& e)
	{
		std::cout << LIGHTRED << "Exception cought: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	TestIncrement()
{
	std::cout << LIGHTCYAN << "--[ " << __func__ << " ]--" << std::endl;
	try
	{
		Bureaucrat B("Charlie", 1);
		B.incrementGrade();
		std::cout << LIGHTYELLOW << "THIS SHOULD NOT BE SEEN: " << B;
	}
	catch(std::exception& e)
	{
		std::cout << LIGHTRED << "Exception cought: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	TestDecriment()
{
	std::cout << LIGHTCYAN << "--[ " << __func__ << " ]--" << std::endl;
	try
	{
		Bureaucrat B("David", 150);
		B.decrementGrade();
		std::cout << LIGHTYELLOW << "THIS SHOULD NOT BE SEEN: " << B;
	}
	catch(std::exception& e)
	{
		std::cout << LIGHTRED << "Exception cought: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	TestDefaultConstructor()
{
	std::cout << LIGHTCYAN << "--[ " << __func__ << " ]--" << std::endl;
	try
	{
		Bureaucrat B;
		std::cout << LIGHTGREEN << "Success" << RESET << ", created: " << B;
	}
	catch(std::exception& e)
	{
		std::cout << LIGHTRED << "Exception cought: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	TestValidInput()
{
	std::cout << LIGHTCYAN << "--[ " << __func__ << " ]--" << std::endl;
	try
	{
		Bureaucrat B("Overlord", 1);
		std::cout << LIGHTGREEN << "Success" << RESET << ", created: " << B;
	}
	catch(std::exception& e)
	{
		std::cout << LIGHTRED << "Exception cought: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	TestCopyConstructor()
{
	Bureaucrat m("Main-Bureaucrat", 42);
	std::cout << LIGHTCYAN << "--[ " << __func__ << " ]--" << std::endl;
	try
	{
		Bureaucrat copy(m);
		std::cout << LIGHTGREEN << "Success" << RESET << ", copied: " << copy << std::endl;
		std::cout << "From original  : " << m << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << LIGHTRED << "Exception cought: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	TestGradeToHigh();
	TestGradeToLow();
	TestIncrement();
	TestDecriment();
	TestDefaultConstructor();
	TestValidInput();
	TestCopyConstructor();

	std::cout	<< LIGHTGREEN
				<< "[OK] "
				<< RESET
				<< "We are still running the main function,"
				<< std::endl
				<< "     although some exceptions occurred…"
				<< RESET
				<< std::endl;

	return (0);
}
