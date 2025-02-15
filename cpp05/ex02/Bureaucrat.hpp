/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:51:28 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/15 17:19:48 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <ostream>
#include "AForm.hpp"

// Forward Declaration
class AForm;

class Bureaucrat
{
public:
	static const unsigned int	HIGHEST_GRADE = 1;
	static const unsigned int	LOWEST_GRADE = 150;

	Bureaucrat();
	Bureaucrat(const std::string& aname, unsigned int agrade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	
	Bureaucrat&		operator=(const Bureaucrat& other);

	std::string		getName() const;
	unsigned int	getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
	void			signForm(AForm& form);
	void			executeForm(const AForm& form);

	class GradeTooHighException : public std::exception {
		const char* what() const throw() override;
	};

	class GradeTooLowException : public std::exception {
		const char* what() const throw() override;
	};

private:
	const std::string	m_name;
	unsigned int		m_grade;

	bool	isValidGrade(unsigned int grade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif