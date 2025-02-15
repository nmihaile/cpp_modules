/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:45:24 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/27 12:19:18 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : m_type("Undefined")
{
	std::cout << "🧬 Animal default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : m_type(other.m_type)
{
	std::cout << "🧬 Animal copy constructor called." << std::endl;
}

AAnimal::~AAnimal()
{	
	std::cout << "🧬 Animal destructor called." << std::endl;
}

AAnimal&	AAnimal::operator = (const AAnimal& other)
{
	if (this == &other)
		return (*this);
	
	m_type = other.m_type;
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


std::string	AAnimal::getType(void) const
{
	return (m_type);
}
