/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:28:34 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 20:51:40 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	log(DEBUG_LOG, "Ice default constructor called.");
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	log(DEBUG_LOG, "Ice copy constructor called.");
}

Ice::~Ice()
{
	log(DEBUG_LOG, "Ice destructor called.");
}

Ice&	Ice::operator = (const Ice& other)
{
	log(DEBUG_LOG, "Ice copy assignement operator overload called.");

	if (this == &other)
		return (*this);

	AMateria::operator=(other);
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt 🧊 at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone() const
{
	log(DEBUG_LOG, "Ice clone called.");

	return ( new Ice() );
}
