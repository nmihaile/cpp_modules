/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:51:29 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/10 21:03:31 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Unnamed_Bureaucrat"), m_grade(Bureaucrat::LOWEST_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string& aname, unsigned int agrade) : m_name(aname)
{	
	if (isValidGrade(agrade))
		m_grade = agrade;
	else
		m_grade = Bureaucrat::LOWEST_GRADE;
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


/* ************************************************************************** */
/* ************************************************************************** */


const char* Bureaucrat::GradeTooHighExcpetion::what() const throw()
{
	return ("Grade is to HIGH!");
}

const char* Bureaucrat::GradeTooLowExcpetion::what() const throw()
{
	return ("Grade is to LOW!");
}


/* ************************************************************************** */
/* ************************************************************************** */


bool	Bureaucrat::isValidGrade(unsigned int grade)
{
	if (grade < Bureaucrat::HIGHEST_GRADE)
	{
		throw ( GradeTooHighExcpetion() );
		return (false);
	}
	if (grade > Bureaucrat::LOWEST_GRADE)
	{
		throw ( GradeTooLowExcpetion() );
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
