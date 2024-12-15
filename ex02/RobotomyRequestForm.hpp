/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:56:11 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/15 15:39:05 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTYELLOW		"\033[93m"
#define LIGHTBLUE		"\033[94m"
#define LIGHTMAGENTA	"\033[95m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string _target);
	~RobotomyRequestForm() override;

	void	execute(const Bureaucrat& executor) const override;

private:
	static const std::string	drill_sounds[20];
	static const std::string	drill_colors[6];
};

#endif