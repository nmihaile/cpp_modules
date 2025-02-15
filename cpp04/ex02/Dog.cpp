/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:09:48 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/27 12:17:21 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(), m_brain(new Brain())
{
	m_type = "🐶 DOG";
	std::cout << "🐶 Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	m_type = "🐶 DOG";
	m_brain = new Brain(*other.m_brain);
	std::cout << "🐶 Dog copy constructor called." << std::endl;
}

Dog::~Dog()
{
	delete(m_brain);
	std::cout << "🐶 Dog destructor called." << std::endl;
}

// Here we use the copy-and-swap idiom
// https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
// ›	first perform the constructive part
// ›	then do the destructive part
Dog& Dog::operator = (const Dog& other)
{
	if (this == &other)
		return (*this);

	Dog tmp(other);
	this->swap(tmp);
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Dog::makeSound() const
{
	std::cout << "🐶 › Woof" << std::endl;
}

Brain*&	Dog::getBrain(void)
{
	return (m_brain);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Dog::swap(Dog& other)
{
	std::string	tmpType		= m_type;
	Brain		*tmpBrain	= m_brain;

	m_type = other.m_type;
	m_brain = other.m_brain;

	other.m_type = tmpType;
	other.m_brain = tmpBrain;
}
