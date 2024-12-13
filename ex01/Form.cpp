/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:08 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/13 16:46:33 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
	m_name("Undefined_Form"),
	m_is_signed(false),
	m_grade_to_sign(HIGHEST_GRADE),
	m_grade_to_exec(HIGHEST_GRADE)
{
	if (m_name.empty())
		throw (std::string("Name can't be empty."));
	validateGrade(m_grade_to_sign);
	validateGrade(m_grade_to_exec);
}

Form::Form(const std::string _name, unsigned int _grade_to_sign, unsigned int _grade_to_exec) :
	m_name(_name),
	m_is_signed(false),
	m_grade_to_sign(_grade_to_sign),
	m_grade_to_exec(_grade_to_exec)
{
	if (m_name.empty())
		throw (std::string("Name can't be empty."));
	validateGrade(_grade_to_sign);
	validateGrade(_grade_to_exec);
}

// as stated in the subject, a Form should NOT-BE-SIGNED on construction
// Thats why we set m_is_signed -> FALSE 
Form::Form(const Form& other) :
	m_name(other.m_name),
	m_is_signed(false),
	m_grade_to_sign(other.m_grade_to_sign),
	m_grade_to_exec(other.m_grade_to_exec)
{
	validateGrade(m_grade_to_sign);
	validateGrade(m_grade_to_exec);
	if (m_name.empty())
		throw (std::string("Name can't be empty."));
}

Form::~Form()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


Form& Form::operator=(const Form& other)
{
	if (this != &other)
		m_is_signed = other.m_is_signed;
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


std::string		Form::getName() const
{
	if (m_name.empty())
		throw (std::string("Form::getName(): m_name is empty -> debugging required…"));
	return ( m_name );
}

bool			Form::isSigned() const
{
	return ( m_is_signed );
}

unsigned int	Form::getGradeToSign() const
{
	if (validateGrade(m_grade_to_sign))
		return ( m_grade_to_sign );
	return (UINT_MAX);
}

unsigned int	Form::getGradeToExec() const
{
	if (validateGrade(m_grade_to_exec))
		return ( m_grade_to_exec );
	return ( UINT_MAX );
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (m_is_signed == true)
	{
		throw (Form::AlreadySignedException());
		return ;
	}
	if (bureaucrat.getGrade() < HIGHEST_GRADE || bureaucrat.getGrade() > LOWEST_GRADE)
	{
		throw (std::string("Bureaucrat: ") + bureaucrat.getName() + std::string(" has and inavlid grade: -> debugging required…"));
		return ;
	}
	if (bureaucrat.getGrade() > m_grade_to_sign)
	{
		throw (GradeTooLowException());
		return ;
	}
	m_is_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Form:: Grade to HIGH!");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Form:: Grade to LOW!");
}

const char* Form::InvalidGradeException::what() const throw() {
	return ("Form:: Invalid Grade!");
}

const char* Form::AlreadySignedException::what() const throw() {
	return ("Form:: Form already signed!");
}


/* ************************************************************************** */
/* ************************************************************************** */


bool	Form::validateGrade(const unsigned int& grade) const
{
	if (grade < HIGHEST_GRADE || grade > LOWEST_GRADE)
	{
		throw (InvalidGradeException());
		return (false);
	}
	return (true);
}


/* ************************************************************************** */
/* ************************************************************************** */


std::ostream& operator<<(std::ostream& os, const Form& form)
{
	return (os << "Form (" << form.getName() << "): "
			<< "[is_signed: " << form.isSigned() << "], "
			<< "[grade_to_sign: " << form.getGradeToSign() << "], "
			<< "[grade_to_exec: " << form.getGradeToExec() << "]" << std::endl );
}
