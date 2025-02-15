/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:09:45 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 20:12:19 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), m_brain(new Brain())
{
	m_type = "😺 CAT";
	std::cout << "😺 Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	m_type = other.m_type;
	m_brain = new Brain(*other.m_brain);
	std::cout << "😺 Cat copy constructor called." << std::endl;
}

Cat::~Cat()
{
	delete(m_brain);
	std::cout << "😺 Cat destructor called." << std::endl;
}

// Here we use the copy-and-swap idiom
// https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
// ›	first perform the constructive part
// ›	then do the destructive part
Cat& Cat::operator = (const Cat& other)
{
	if (this == &other)
		return (*this);

	Cat	tmp(other);
	this->swap(tmp);
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Cat::makeSound(void) const
{
	std::cout << "😺 › Miau" << std::endl;	
}

Brain*&	Cat::getBrain(void)
{
	return (m_brain);
}


/* ************************************************************************** */
/* ************************************************************************** */

void	Cat::swap(Cat& other)
{
	std::string	tmpType		= m_type;
	Brain		*tmpBrain	= m_brain;

	m_type = other.m_type;
	m_brain = other.m_brain;

	other.m_type = tmpType;
	other.m_brain = tmpBrain;	
}

