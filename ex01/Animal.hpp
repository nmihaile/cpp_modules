/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:45:26 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/29 15:18:51 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

// In C++, if a class has virtual functions, it should also have a virtual
// destructor to ensure that the destructor of the derived class is called
// when an object is deleted through a base class pointer.

class Animal
{
public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();

	Animal&	operator = (const Animal& other);

	virtual void	makeSound(void) const;

	std::string		getType(void) const;

protected:
	std::string	m_type;
};

#endif
