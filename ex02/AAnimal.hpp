/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:45:26 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/27 14:30:17 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AANIMAL_HPP
#define AaANIMAL_HPP

#include <string>
#include <iostream>

// In C++, if a class has virtual functions, it should also have a virtual
// destructor to ensure that the destructor of the derived class is called
// when an object is deleted through a base class pointer.

// Abstract Animal AAnimal

class AAnimal
{
public:
	virtual ~AAnimal();

	AAnimal&	operator = (const AAnimal& other);

	virtual void	makeSound(void) const =0;

	std::string	getType(void) const;

protected:
	AAnimal();
	AAnimal(const AAnimal& other);

	std::string	m_type;
};

#endif
