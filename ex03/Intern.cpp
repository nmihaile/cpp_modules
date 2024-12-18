/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:39:25 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/18 17:58:32 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char	*Intern::formSpecifiers[Intern::FORM_COUNT] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

const std::function<AForm*(std::string& _target)>	Intern::formFactory[Intern::FORM_COUNT] = {
	[](std::string& _target) { return ( new ShrubberyCreationForm(_target) ); },
	[](std::string& _target) { return ( new RobotomyRequestForm(_target) ); },
	[](std::string& _target) { return ( new PresidentialPardonForm(_target) ); }
};

// Lambdas functions are inline, anonymous functions
// [] is the capture list. An empty list ([]) means the lambda does not capture
// any variables from its surrounding scope

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
		if (std::strcmp(_name.c_str(), formSpecifiers[i]) == 0)
			return( formFactory[i](_target) );
	throw ( Intern::InvalidFormSpecifierException() );
	return (nullptr);
}

const char	*Intern::InvalidFormSpecifierException::what() const throw()
{
	return ("Intern::makeForm() Invalid form specifier: no matching form found.");
}
