/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:51:28 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/14 19:59:23 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <ostream>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string& aname, unsigned int agrade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	
	Bureaucrat& operator=(const Bureaucrat& other);

	std::string		getName() const;
	unsigned int	getGrade() const;
	void			incrementGrade();
	void			decrementGrade();

	class GradeTooHighExcpetion : public std::exception {
		const char* what() const throw() override;
	};

	class GradeTooLowExcpetion : public std::exception {
		const char* what() const throw() override;
	};

	static const unsigned int HIGHEST_GRADE = 1;
	static const unsigned int LOWEST_GRADE = 150;

private:
	const std::string	m_name;
	unsigned int		m_grade;

	bool	isValidGrade(unsigned int grade);
};

std::ostream& operator<< (std::ostream& os, const Bureaucrat& rhs);

#endif