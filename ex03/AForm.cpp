/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:08 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/17 19:01:58 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
	m_name("Undefined_Form"),
	m_target("Undefined_Target"),
	m_is_signed(false),
	m_grade_to_sign(HIGHEST_GRADE),
	m_grade_to_exec(HIGHEST_GRADE)
{
	if (m_name.empty())
		throw (std::string("Name can't be empty."));
	validateGrade(m_grade_to_sign);
	validateGrade(m_grade_to_exec);
}

AForm::AForm(const std::string& _name, unsigned int _grade_to_sign, unsigned int _grade_to_exec)
	:	m_name(_name),
		m_target("Undefined_Target"),
		m_is_signed(false),
		m_grade_to_sign(_grade_to_sign),
		m_grade_to_exec(_grade_to_exec)
{
	if (m_name.empty())
		throw (std::string("Name can't be empty."));
	validateGrade(_grade_to_sign);
	validateGrade(_grade_to_exec);
}

AForm::AForm(const std::string& _name, const std::string& _target, unsigned int _grade_to_sign, unsigned int _grade_to_exec)
	:	m_name(_name),
		m_target(_target),
		m_is_signed(false),
		m_grade_to_sign(_grade_to_sign),
		m_grade_to_exec(_grade_to_exec)
{
	if (m_name.empty())
		throw (std::string("Name can't be empty."));
	if (m_target.empty())
		throw (getName() + std::string(" Target can't be empty."));
	validateGrade(_grade_to_sign);
	validateGrade(_grade_to_exec);
}

// as stated in the subject, a Form should NOT-BE-SIGNED on construction
// Thats why we set m_is_signed -> FALSE 
AForm::AForm(const AForm& other) :
	m_name(other.getName()),
	m_target(other.getTarget()),
	m_is_signed(false),
	m_grade_to_sign(other.m_grade_to_sign),
	m_grade_to_exec(other.m_grade_to_exec)
{
	validateGrade(m_grade_to_sign);
	validateGrade(m_grade_to_exec);
	if (m_name.empty())
		throw (std::string("Name can't be empty."));
	if (m_target.empty())
		throw (getName() + std::string(" Target can't be empty."));
}

AForm::~AForm()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


// AForm& AForm::operator=(const AForm& other)
// {
// 	if (this != &other)
// 		m_is_signed = other.m_is_signed;
// 	return (*this);
// }


/* ************************************************************************** */
/* ************************************************************************** */


std::string		AForm::getName() const
{
	if (m_name.empty())
		throw (std::string("AForm::getName(): m_name is empty -> debugging required…"));
	return ( m_name );
}

std::string		AForm::getTarget() const
{
	if (m_target.empty())
		throw (getName() + std::string("::getTarget(): m_target is empty -> debugging required…"));
	return ( m_target );
}

bool			AForm::isSigned() const
{
	return ( m_is_signed );
}

unsigned int	AForm::getGradeToSign() const
{
	if (validateGrade(m_grade_to_sign))
		return ( m_grade_to_sign );
	return (UINT_MAX);
}

unsigned int	AForm::getGradeToExec() const
{
	if (validateGrade(m_grade_to_exec))
		return ( m_grade_to_exec );
	return ( UINT_MAX );
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (m_is_signed == true)
	{
		throw (AForm::AlreadySignedException());
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

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Grade to HIGH!");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Grade to LOW!");
}

const char* AForm::InvalidGradeException::what() const throw() {
	return ("Invalid Grade!");
}

const char* AForm::AlreadySignedException::what() const throw() {
	return ("Form already signed!");
}

const char* AForm::NotSignedException::what() const throw() {
	return ("Form is not signed yet.");
}


/* ************************************************************************** */
/* ************************************************************************** */


bool	AForm::validateGrade(const unsigned int& grade) const
{
	if (grade < HIGHEST_GRADE || grade > LOWEST_GRADE)
	{
		throw (InvalidGradeException());
		return (false);
	}
	return (true);
}

bool	AForm::checkForm(const Bureaucrat& bureaucrat) const
{
	if (m_is_signed == false)
	{
		throw ( AForm::NotSignedException() );
		return (false);
	}
	if (bureaucrat.getGrade() > m_grade_to_exec)
	{
		throw ( AForm::GradeTooLowException() );
		return (false);
	}
	return (true);
}


/* ************************************************************************** */
/* ************************************************************************** */


std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	return (os << "Form \"" << form.getName() << "\": "
			<< "[Target: " << form.getTarget() << "], "
			<< "[is_signed: " << form.isSigned() << "], "
			<< "[grade_to_sign: " << form.getGradeToSign() << "], "
			<< "[grade_to_exec: " << form.getGradeToExec() << "]" );
}
