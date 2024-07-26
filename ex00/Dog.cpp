/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:09:48 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 13:56:23 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	m_type = "DOG";
}

Dog::Dog(const Dog& other)
{
	m_type = other.m_type;
}

Dog::~Dog()
{
}

Dog& Dog::operator = (const Dog& other)
{
	if (this == &other)
		return (*this);
	
	m_type = other.m_type;
	return (*this);
}

void	Dog:: makeSound(void)
{
	std::cout << "🐶 › Woof" << std::endl;
}
