/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:09 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/14 18:45:27 by nmihaile         ###   ########.fr       */
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

#define HIGHEST_GRADE	1
#define LOWEST_GRADE	150

// Forward Declaration
class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(const std::string _name, unsigned int _grade_to_sign, unsigned int _grade_to_exec);
	AForm(const AForm& other);
	virtual ~AForm();

	AForm& 			operator=(const AForm& other);

	std::string		getName() const;
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
	const std::string	m_name;
	bool				m_is_signed;
	const unsigned int	m_grade_to_sign;
	const unsigned int	m_grade_to_exec;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
