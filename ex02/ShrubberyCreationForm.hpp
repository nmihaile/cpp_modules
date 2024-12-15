/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:29:07 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/15 17:24:36 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>

class ShrubberyCreationForm : public AForm
{
public:
	static const unsigned int	REQUIRED_SIGN_GRADE = 145;
	static const unsigned int	REQUIRED_EXEC_GRADE = 137;

	ShrubberyCreationForm(std::string _target);
	~ShrubberyCreationForm() override;

	void	execute(const Bureaucrat& executor) const override;

private:
	bool	write_ASCII_tree() const;

	static const std::string	m_trees[3];
};

#endif