/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:22:03 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/22 21:22:48 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	:	ClapTrap("clap_name_Unnamed"),
		ScavTrap(),
		FragTrap()
{
	m_name = "Unnamed";

	std::cout << "DiamondTrap default constructor called: " << this->m_name << std::endl;	
}

DiamondTrap::DiamondTrap(const std::string name)
	:	ClapTrap("clap_name_" + name),
		ScavTrap(name),
		FragTrap(name)
{
	m_name = name;

	std::cout << "DiamondTrap name constructor called: " << m_name << std::endl;
}

// The base 'class ClapTrap' must be explicitly initialized in the copy constructor
// because DiamondTrap contains a base class subobject of type ClapTrap.
// Docker/Linux tells me that I also have to explicitly initialize ScavTrap && FragTrap
DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:	ClapTrap(other),
		ScavTrap(other),
		FragTrap(other),
		m_name("Unnamed")
{
	*this = other;
	
	std::cout << "DiamondTrap copy constructor called: " << other.m_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called: " << m_name << std::endl;
}


/* ************************************************************************** */
/* ************************************************************************** */


void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::who_am_I(void)
{	
	std::cout	<< "My DiamondTrap name is: " << m_name
				<< ", and my ClapTrap is " << this->get_name() << std::endl;
}

DiamondTrap&	DiamondTrap::operator = (const DiamondTrap& other)
{	
	std::cout << "DiamondTrap copy assignement operator overload called: " << m_name << " = " << other.m_name << std::endl;

	if (this != &other)
	{
		m_name				= other.m_name;
		m_hit_points		= other.m_hit_points;
		m_energy_points		= other.m_energy_points;
		m_attack_damage		= other.m_attack_damage;
		ClapTrap::m_name	= other.ClapTrap::m_name;
	}
	return (*this);
}
