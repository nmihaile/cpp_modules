/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:46:00 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/17 11:23:17 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm()
// :	AForm("PresidentialPardonForm", REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE),
// 	m_target("Undefined_target")
// {
// }

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
	:	AForm("PresidentialPardonForm", _target, REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	:	AForm(other.getName(), other.getTarget(), other.REQUIRED_SIGN_GRADE, other.REQUIRED_EXEC_GRADE)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


// PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
// {
// 	if (this != &rhs)
// 	{
// 		AForm::operator=(rhs);
// 		try
// 		{
// 			m_target = rhs.getTarget();
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cout	<< "PresidentialPardonForm::operator=() assignment failed to set m_target from Rvalue \""
// 						<< rhs.getName() << "\" because "
// 						<< e.what() << "." << std::endl;
// 			throw ;
// 		}
// 		catch(...)
// 		{
// 			std::cout	<< "PresidentialPardonForm::operator=() assignment failed to set m_target from Rvalue \""
// 						<< rhs.getName() << "\" and got an unknown/default exception type." << std::endl;
// 			throw ;
// 		}
// 	}
// 	return (*this);
// }

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
