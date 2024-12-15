/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:56:09 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/15 15:58:02 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
	: AForm(_target, 72, 75)
{
	std::srand(std::time(nullptr));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	validateGrade(getGradeToExec());
	if (executor.getGrade() < HIGHEST_GRADE || executor.getGrade() > LOWEST_GRADE)
		throw (std::string("Executor has INAVLID_GRADE!"));

	checkForm(executor);

	// make drilling noises
	std::cout << "🔊 ";
	int noise_count = std::rand() % 20 + 10;
	for (int i = noise_count; i--;)
	{
		if (i < noise_count - 1)
			std::cout << drill_colors[std::rand() % 6] << "-";
		else
			std::cout << drill_colors[std::rand() % 6] << "";

		std::cout << drill_colors[std::rand() % 6] << drill_sounds[std::rand() % 20] << std::flush;

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	if (std::rand() % 2 == 0)
		std::cout	<< RESET << std::endl << "\""
					<< getName() << "\""
					<< " has been robotomized." << std::endl;
	else
		std::cout	<< RESET << std::endl
					<< "Failed to robotomy target: " << "\""
					<< getName() << "\"" << std::endl;
}


/* ************************************************************************** */
/* ************************************************************************** */


const std::string	RobotomyRequestForm::drill_sounds[20] = {
	"Brr",
	"Vrr",
	"Zzz",
	"Drr",
	"Tkk",
	"Krk",
	"Grr",
	"Bzz",
	"Prr",
	"Trr",
	"Zrk",
	"Brk",
	"...",
	"Zzt",
	"Dzk",
	"Vnk",
	"Tzz",
	"Rrt",
	"Grk",
	"Dzt"
};

const std::string	RobotomyRequestForm::drill_colors[6] = {
	"\033[91m",
	"\033[92m",
	"\033[93m",
	"\033[94m",
	"\033[95m",
	"\033[96m"
};
