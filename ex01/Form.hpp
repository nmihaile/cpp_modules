/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:08:09 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/13 11:41:24 by nmihaile         ###   ########.fr       */
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

#include "authority.h"
#include "Bureaucrat.hpp"

class Form
{
public:
	Form();
	Form(const std::string _name, unsigned int _grade_to_sign, unsigned int _grade_to_exec);
	Form(const Form& other);
	~Form();

	Form& 			operator=(const Form& other);

	std::string		getName() const;
	bool			isSigned() const;
	unsigned int	getGradeToSign() const;
	unsigned int	getGradeToExec() const;
	void			beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
		const char* what() const throw() override;
	};

	class GradeTooLowException : public std::exception {
		const char* what() const throw() override;
	};

private:
	const std::string	m_name;
	bool				m_is_signed;
	const unsigned int	m_grade_to_sign;
	const unsigned int	m_grade_to_exec;

	bool	validateGrade(const unsigned int& grade) const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif