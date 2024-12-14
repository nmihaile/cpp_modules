/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:29:07 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/14 18:30:10 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string _target);
	~ShrubberyCreationForm();

	void	execute(const Bureaucrat& executor) const;
	
private:
	bool	write_ASCII_tree() const;

	static const std::string	m_trees[3];
};

#endif