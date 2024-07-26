/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:45:24 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 15:13:14 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : m_type("Undefined")
{
}

Animal::Animal(const Animal& other) : m_type(other.m_type)
{
}

Animal::~Animal()
{	
}

Animal&	Animal::operator = (const Animal& other)
{
	if (this == &other)
		return (*this);
	
	m_type = other.m_type;
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Animal::makeSound(void) const
{
	std::cout << "🤐" << std::endl;	
}

std::string	Animal::getType(void) const
{
	return (m_type);
}
