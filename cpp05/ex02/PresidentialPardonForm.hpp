/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:46:02 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/17 11:16:27 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	static const unsigned int	REQUIRED_SIGN_GRADE = 25;
	static const unsigned int	REQUIRED_EXEC_GRADE = 5;

	PresidentialPardonForm(std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm() override;

	void		execute(const Bureaucrat& executor) const override;

private:
	PresidentialPardonForm() =delete;
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs) = delete;
};

#endif