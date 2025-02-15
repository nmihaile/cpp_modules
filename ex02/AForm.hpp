/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:09 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/17 10:35:32 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <ostream>
#include <climits>
#include "Bureaucrat.hpp"

// Forward Declaration
class Bureaucrat;

class AForm
{
public:
	static const unsigned int	HIGHEST_GRADE = 1;
	static const unsigned int	LOWEST_GRADE = 150;

	AForm();
	AForm(const std::string& _name, unsigned int _grade_to_sign, unsigned int _grade_to_exec);
	AForm(const std::string& _name, const std::string& _target, unsigned int _grade_to_sign, unsigned int _grade_to_exec);
	AForm(const AForm& other);
	virtual ~AForm();

	std::string		getName() const;
	std::string		getTarget() const;
	bool			isSigned() const;
	unsigned int	getGradeToSign() const;
	unsigned int	getGradeToExec() const;
	void			beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(const Bureaucrat& executor) const =0;

	class GradeTooHighException : public std::exception {
		const char* what() const throw() override;
	};

	class GradeTooLowException : public std::exception {
		const char* what() const throw() override;
	};

	class InvalidGradeException : public std::exception {
		const char* what() const throw() override;
	};

	class AlreadySignedException : public std::exception {
		const char* what() const throw() override;
	};

	class NotSignedException : public std::exception {
		const char* what() const throw() override;
	};

protected:
	bool	validateGrade(const unsigned int& grade) const;
	bool	checkForm(const Bureaucrat& bureaucrat) const;

private:
	AForm& 			operator=(const AForm& other) = delete;

	const std::string	m_name;
	const std::string	m_target;
	bool				m_is_signed;
	const unsigned int	m_grade_to_sign;
	const unsigned int	m_grade_to_exec;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
