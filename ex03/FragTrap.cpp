/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:57:46 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/23 15:46:33 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed")
{
	m_hit_points	= 100;
	m_energy_points	= 100;
	m_attack_damage	= 30;

	std::cout << "FragTrap default constructor called: " << this->m_name << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	m_hit_points	= 100;
	m_energy_points	= 100;
	m_attack_damage	= 30;

	std::cout << "FragTrap name constructor called: " << m_name << std::endl;
}

// The base 'class ClapTrap' must be explicitly initialized in the copy constructor
// because FragTrap contains a base class subobject of type ClapTrap.
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called: " << other.m_name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called: " << m_name << std::endl;
}

FragTrap&	FragTrap::operator = (const FragTrap& other)
{
	std::cout << "FragTrap copy assignement operator overload called: " << m_name << " = " << other.m_name << std::endl;

	if (this == &other)
		return (*this);

	ClapTrap::operator=(static_cast<const ClapTrap&>(other));
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	FragTrap::highFivesGuys(void)
{
	if (this->is_dead("request_high_five"))
		return ;

	std::cout	<< "FragTrap "	<< m_name
				<< " requests a high 5!" << std::endl;
}
