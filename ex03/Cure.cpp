/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:00:11 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 20:53:12 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	log(DEBUG_LOG, "Cure default constructor called.");
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	log(DEBUG_LOG, "Cure copy constructor called.");
}

Cure::~Cure()
{
	log(DEBUG_LOG, "Cure destructor called.");
}


Cure&	Cure::operator = (const Cure& other)
{
	log(DEBUG_LOG, "Cure copy assignement operator overload called.");

	if (this == &other)
		return (*this);
	
	AMateria::operator=(other);
	return (*this);
}



/* ************************************************************************** */
/* ************************************************************************** */


void		Cure::use(ICharacter& target)
{
	std::cout << "* heals 🩹 " << target.getName() << "’s wounds *" << std::endl;
}

AMateria*	Cure::clone() const
{
	log(DEBUG_LOG, "Cure clone called.");

	return ( new Cure() );
}

