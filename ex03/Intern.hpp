/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:39:27 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/18 20:00:52 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>
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
	typedef AForm				*(*createFunc)(const std::string&);

	static const std::string	formSpecifiers[Intern::FORM_COUNT];
	static const createFunc		formFactory[Intern::FORM_COUNT];
	static AForm				*createSchrubberyCreationForm(const std::string& _target);
	static AForm				*createRobotomyRequestForm(const std::string& _target);
	static AForm				*createPresidentialPardonForm(const std::string& _target);

	Intern(const Intern&) = delete;
	Intern&	operator=(const Intern&) = delete;

};

#endif