/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:09:45 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 17:02:11 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	m_type = "🦠😺 WrongCAT";
	std::cout << "🦠😺 WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	m_type = other.m_type;
	std::cout << "🦠😺 WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "🦠😺 WrongCat destructor called." << std::endl;
}


WrongCat& WrongCat::operator = (const WrongCat& other)
{
	if (this == &other)
		return (*this);

	m_type = other.m_type;
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	WrongCat::makeSound(void) const
{
	std::cout << "🦠😺 › Grunz" << std::endl;	
}
