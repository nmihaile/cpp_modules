/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:39:25 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/18 19:59:56 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string	Intern::formSpecifiers[Intern::FORM_COUNT] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

const Intern::createFunc	Intern::formFactory[Intern::FORM_COUNT] = {
	&Intern::createSchrubberyCreationForm,
	&Intern::createRobotomyRequestForm,
	&Intern::createPresidentialPardonForm
};

AForm	*Intern::createSchrubberyCreationForm(const std::string& _target)
{
	return ( new ShrubberyCreationForm(_target) );
}

AForm	*Intern::createRobotomyRequestForm(const std::string& _target)
{
	return ( new RobotomyRequestForm(_target) );
}

AForm	*Intern::createPresidentialPardonForm(const std::string& _target)
{
	return ( new PresidentialPardonForm(_target) );
}


/* ************************************************************************** */
/* ************************************************************************** */


Intern::Intern()
{
}

// Intern::Intern(const Intern&)
// {
// }

Intern::~Intern()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


// Intern&	Intern::operator=(const Intern&)
// {
// 	return (*this);
// }

AForm	*Intern::makeForm(std::string _name, std::string _target)
{
	for (size_t i = 0; i < Intern::FORM_COUNT; ++i)
		if (formSpecifiers[i].compare(_name) == 0)
			return( formFactory[i](_target) );
	throw ( Intern::InvalidFormSpecifierException() );
	return (nullptr);
}

const char	*Intern::InvalidFormSpecifierException::what() const throw()
{
	return ("Intern::makeForm() Invalid form specifier: no matching form found.");
}
