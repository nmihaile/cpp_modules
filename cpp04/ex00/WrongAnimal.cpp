/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:45:24 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 15:46:18 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("Undefined")
{
	std::cout << "🦠 WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : m_type(other.m_type)
{
	std::cout << "🦠 WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{	
	std::cout << "🦠 WrongAnimal destructor called." << std::endl;
}

WrongAnimal&	WrongAnimal::operator = (const WrongAnimal& other)
{
	if (this == &other)
		return (*this);
	
	m_type = other.m_type;
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	WrongAnimal::makeSound(void) const
{
	std::cout << "🦠🤐🦠" << std::endl;	
}

std::string	WrongAnimal::getType(void) const
{
	return (m_type);
}
