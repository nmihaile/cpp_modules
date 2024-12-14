/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:51:29 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/14 12:11:15 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Unnamed_Bureaucrat"), m_grade(LOWEST_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string& aname, unsigned int agrade) : m_name(aname)
{	
	if (isValidGrade(agrade))
		m_grade = agrade;
	else
		m_grade = LOWEST_GRADE;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : m_name(other.m_name), m_grade(other.m_grade)
{
}

Bureaucrat::~Bureaucrat()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


std::string	Bureaucrat::getName() const
{
	if (m_name.empty())
		return ("<Bureaucrat::m_name is empty>");
	return (m_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (m_grade);
}

void	Bureaucrat::incrementGrade()
{	
	if (isValidGrade(m_grade - 1))
		m_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (isValidGrade(m_grade + 1))
		m_grade++;
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout	<< this->getName() << " couldn’t sign \""
					<< form.getName() << "\" because "
					<< e.what() << "." << std::endl;

		// Advanced Exception Handling:
		// Here we RETHROW the original exception !!!
		throw ;
		return ;
	}
	std::cout << this->getName() << " signed \"" << form.getName() << "\"" << std::endl;
}


/* ************************************************************************** */
/* ************************************************************************** */


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat:: Grade is to HIGH!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat:: Grade is to LOW!");
}


/* ************************************************************************** */
/* ************************************************************************** */


bool	Bureaucrat::isValidGrade(unsigned int grade)
{
	if (grade < HIGHEST_GRADE)
	{
		throw ( GradeTooHighException() );
		return (false);
	}
	if (grade > LOWEST_GRADE)
	{
		throw ( GradeTooLowException() );
		return (false);
	}
	return (true);
}


/* ************************************************************************** */
/* ************************************************************************** */


std::ostream& operator<< (std::ostream& os, const Bureaucrat& rhs)
{
	return ( os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl );
}
