/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:39:27 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/17 17:35:26 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>
#include <functional>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	static const size_t	FORM_COUNT = 3;
	Intern();
	~Intern();
	
	AForm	*makeForm(std::string _name, std::string _target);

	class InvalidFormSpecifierException : public std::exception {
		const char *what() const throw() override;
	};

private:
	static const std::string									formSpecifiers[Intern::FORM_COUNT];
	static const std::function<AForm*(std::string& _target)>	formFactory[Intern::FORM_COUNT];
	Intern(const Intern&) = delete;
	Intern&	operator=(const Intern&) = delete;
};

#endif