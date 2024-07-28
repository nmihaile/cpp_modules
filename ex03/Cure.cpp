/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:00:11 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 13:06:32 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& other) : AMateria(other)
{
}

Cure::~Cure()
{
}


Cure&	Cure::operator = (const Cure& other)
{
	if (this == &other)
		return (*this);
	
	AMateria::operator=(other);
	return (*this);
}



/* ************************************************************************** */
/* ************************************************************************** */


void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria*	Cure::clone() const
{
	return ( new Cure() );
}

