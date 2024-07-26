/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:09:45 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 15:19:45 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	m_type = "😺 CAT";
	std::cout << "😺 Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat& other)
{
	m_type = other.m_type;
	std::cout << "😺 Cat copy constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "😺 Cat destructor called." << std::endl;
}


Cat& Cat::operator = (const Cat& other)
{
	if (this == &other)
		return (*this);

	m_type = other.m_type;
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Cat::makeSound(void) const
{
	std::cout << "😺 › Miau" << std::endl;	
}
