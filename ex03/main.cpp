/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:08:21 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/17 19:32:02 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

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

static const char *rainbow_colors[6] = {
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
		std::cout << rainbow_colors[col++ % 6] << *it;
	}
	std::cout << RESET <<std::endl;
}

int	main()
{

	// std::cout << "Interns are Welcome" << std::endl;
	rainbow_print(".~ Interns are Welcome ~.");

	Intern intern;

	AForm *form;

	form = intern.makeForm("robotomy request", "R2-D2");

	std::cout << *form << std::endl;

	delete (form);

	try
	{
		form = intern.makeForm("enrole @ 42", "student");
		std::cout << *form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
