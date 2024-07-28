/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:23:46 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 12:40:10 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : m_type("undefined")
{
}

AMateria::AMateria(const AMateria& other) : m_type(other.m_type)
{
}


AMateria::AMateria(std::string const & type) : m_type(type)
{
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator = (const AMateria& other)
{
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
