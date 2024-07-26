/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:09:45 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 14:03:02 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	m_type = "😺 CAT";
}

Cat::Cat(const Cat& other)
{
	m_type = other.m_type;
}

Cat::~Cat()
{
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


void	Cat::makeSound(void)
{
	std::cout << "😺 › Miau" << std::endl;	
}
