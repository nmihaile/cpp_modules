/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:45:26 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/27 12:32:42 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

// In C++, if a class has virtual functions, it should also have a virtual
// destructor to ensure that the destructor of the derived class is called
// when an object is deleted through a base class pointer.

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	~WrongAnimal();

	WrongAnimal&	operator = (const WrongAnimal& other);

	void		makeSound(void) const;
	std::string	getType(void) const;

protected:
	std::string	m_type;
};

#endif
