/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:08:21 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/18 18:08:13 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <exception>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#define BOLD			"\033[1m"
#define GREEN			"\033[32m"
#define BLUE			"\033[34m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTYELLOW		"\033[93m"
#define LIGHTBLUE		"\033[94m"
#define LIGHTMAGENTA	"\033[95m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

// RainbowColorCount:
#define RCC 6

static const char *rainbow_colors[RCC] = {
	"\033[91m",
	"\033[93m",
	"\033[92m",
	"\033[96m",
	"\033[94m",
	"\033[95m"
};

void	rainbow_print(std::string str)
{
	static size_t	col;
	std::cout << BOLD;
	for(std::string::iterator it = str.begin(); it < str.end(); ++it)
	{
		std::cout << rainbow_colors[col++ % RCC] << *it;
	}
	std::cout << RESET <<std::endl;
}

int	main()
{
	std::cout << std::endl;
	rainbow_print(".~ Interns are welcome ~.");

	Intern intern;
	AForm *form = nullptr;

	rainbow_print("\n-------------------------");
	try {
		form = intern.makeForm("Howdy request", "R2-D2");
		if (form)
		{
			std::cout << *form << std::endl;
			Bureaucrat yoda("Yoda", 1);
			yoda.signForm(*form);
			yoda.executeForm(*form);
			std::cout << *form << std::endl;
			delete (form);
			form = nullptr;
		}
	}
	catch (std::exception& e) {
		std::cout << LIGHTRED << e.what() << RESET << std::endl;
	}
	if (form)
	{
		delete (form);
		form = nullptr;
	}

	
	rainbow_print("\n-------------------------");
	try {
		form = intern.makeForm("robotomy request", "R2-D2");
		if (form)
		{
			std::cout << *form << std::endl;
			Bureaucrat yoda("Yoda", 1);
			yoda.signForm(*form);
			yoda.executeForm(*form);
			delete (form);
			form = nullptr;
		}
	}
	catch (std::exception& e) {
		std::cout << LIGHTRED << e.what() << RESET << std::endl;
	}
	if (form)
	{
		delete (form);
		form = nullptr;
	}

	rainbow_print("\n-------------------------");
	try {
		form = intern.makeForm("presidential pardon", "Julian Assange");
		if (form)
		{
			std::cout << *form << std::endl;
			Bureaucrat yoda("Yoda", 1);
			yoda.signForm(*form);
			yoda.executeForm(*form);
			delete (form);
			form = nullptr;
		}
	}
	catch (std::exception& e) {
		std::cout << LIGHTRED << e.what() << RESET << std::endl;
	}
	if (form)
	{
		delete (form);
		form = nullptr;
	}

	rainbow_print("\n-------------------------");
	try {
		form = intern.makeForm("shrubbery creation", "42_school");
		if (form)
		{
			std::cout << *form << std::endl;
			Bureaucrat yoda("Yoda", 1);
			yoda.signForm(*form);
			yoda.executeForm(*form);
			delete (form);
			form = nullptr;
		}
	}
	catch (std::exception& e) {
		std::cout << LIGHTRED << e.what() << RESET << std::endl;
	}
	if (form)
	{
		delete (form);
		form = nullptr;
	}

	rainbow_print("\n-------------------------");
	try {
		form = intern.makeForm("presidential pardon", "Edward Snowden");
		if (form)
		{
			std::cout << *form << std::endl;
			Bureaucrat Leia("Princess Leia", 25);
			Leia.signForm(*form);
			Leia.executeForm(*form);
			delete (form);
			form = nullptr;
		}
	}
	catch (std::exception& e) {
		std::cout << LIGHTRED << e.what() << RESET << std::endl;
	}
	if (form)
	{
		delete (form);
		form = nullptr;
	}

	rainbow_print("\n------------------------ ");
	rainbow_print("THANK YOU -> WE ARE DONE\n");
	
	return (0);
}
