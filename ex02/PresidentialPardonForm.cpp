/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:46:00 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/16 11:56:02 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:	AForm("PresidentialPardonForm", REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE),
	m_target("Undefined_target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
:	AForm("PresidentialPardonForm", REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE),
	m_target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
:	AForm(other.getName(), other.REQUIRED_SIGN_GRADE, other.REQUIRED_EXEC_GRADE),
	m_target(other.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		try
		{
			m_target = rhs.getTarget();
		}
		catch(const std::exception& e)
		{
			std::cout	<< "PresidentialPardonForm::operator=() assignment failed to set m_target from Rvalue \""
						<< rhs.getName() << "\" because "
						<< e.what() << "." << std::endl;
			throw ;
		}
		catch(...)
		{
			std::cout	<< "PresidentialPardonForm::operator=() assignment failed to set m_target from Rvalue \""
						<< rhs.getName() << "\" and got an unknown/default exception type." << std::endl;
			throw ;
		}
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	if (m_target.empty())
	{
		throw (std::string("PresidentialPardonForm::getTarget(): m_target is empty -> debugging required…"));
		return (nullptr);
	}
	return ( m_target );
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	validateGrade(getGradeToExec());

	if (executor.getGrade() < HIGHEST_GRADE || executor.getGrade() > LOWEST_GRADE)
		throw (std::string("Executor has INAVLID_GRADE!"));

	checkForm(executor);
	
	std::cout	<< executor.getName() << ": "
				<< "\""<< getTarget() << "\" "
				<< "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
