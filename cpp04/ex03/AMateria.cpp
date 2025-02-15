/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:23:46 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 20:49:39 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : m_type("undefined_materia")
{
	log(DEBUG_LOG, "AMateria default constructor called.");
}

AMateria::AMateria(const AMateria& other) : m_type(other.m_type)
{
	log(DEBUG_LOG, "AMateria copy constructor called.");
}


AMateria::AMateria(std::string const & type) : m_type(type)
{
	log(DEBUG_LOG, "AMateria name constructor called.");
}

AMateria::~AMateria()
{
	log(DEBUG_LOG, "AMateria destructor called.");
}

AMateria&	AMateria::operator = (const AMateria& other)
{
	log(DEBUG_LOG, "AMateria copy assignement operator overload called.");

	if (this == &other)
		return (*this);

	m_type = other.m_type;
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void AMateria::use(ICharacter&)
{
	std::cerr << "* Abstract class AMateria can't be used *" << std::endl;
}

const std::string& AMateria::getType() const
{
	return (m_type);
}
