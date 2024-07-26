/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:45:26 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 15:07:39 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal& other);
	~Animal();

	Animal&	operator = (const Animal& other);

	virtual void	makeSound(void) const;

	std::string	getType(void) const;

protected:
	std::string	m_type;
};

#endif
