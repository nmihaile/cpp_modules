/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:09:48 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 15:20:03 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	m_type = "🐶 DOG";
	std::cout << "🐶 Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& other)
{
	m_type = other.m_type;
	std::cout << "🐶 Dog copy constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "🐶 Dog destructor called." << std::endl;
}

Dog& Dog::operator = (const Dog& other)
{
	if (this == &other)
		return (*this);
	
	m_type = other.m_type;
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Dog:: makeSound(void) const
{
	std::cout << "🐶 › Woof" << std::endl;
}
