/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:18:03 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/23 14:57:25 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	:	ClapTrap(),
		m_state(ST_IDLE),
		m_guardedGateID(0)
{
	m_hit_points	= 100;
	m_energy_points	= 50;
	m_attack_damage	= 20;

	std::cout << "ScavTrap default constructor called: " << this->m_name << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
	: ClapTrap(name),
		m_state(ST_IDLE),
		m_guardedGateID(0)
{
	m_name			= name;
	m_hit_points	= 100;
	m_energy_points	= 50;
	m_attack_damage	= 20;

	std::cout << "ScavTrap name constructor called: " << m_name << std::endl;
}

// The base 'class ClapTrap' must be explicitly initialized in the copy constructor
// because ScavTrap contains a base class subobject of type ClapTrap.
ScavTrap::ScavTrap(const ScavTrap& other)
	:	ClapTrap(other),
		m_state(other.m_state),
		m_guardedGateID(other.m_guardedGateID)
{
	std::cout << "ScavTrap copy constructor called: " << other.m_name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called: " << m_name << std::endl;
}

ScavTrap&	ScavTrap::operator = (const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignement operator overload called: " << m_name << " = " << other.m_name << std::endl;

	if (this != &other)
		return (*this);

	ClapTrap::operator=(static_cast<const ClapTrap&>(other));
	m_state			= other.m_state;
	m_guardedGateID	= other.m_guardedGateID;

	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	ScavTrap::attack(const std::string& target)
{
	if (this->is_dead("attack") || this->out_of_energy("attack"))
		return ;

	std::cout	<< "ScavTrap "	<< m_name
				<< " attacks "	<< target
				<< ", causing "	<< m_attack_damage
				<< " points of damage!" << std::endl;
	m_energy_points--;

}

void 	ScavTrap::guardGate(unsigned int id)
{
	std::string	action("guard gate ");
	std::ostringstream os;
	os << id;
	action += os.str();
	if (this->is_dead(action))
		return ;

	m_guardedGateID	= id;

	if (m_guardedGateID > 0)
	{
		m_state		= ST_GATE_KEEPER;
		std::cout	<< "ScavTrap "	<< m_name
					<< " is now in Gate keeper mode." << std::endl;
	}
	else
	{
		m_state		= ST_IDLE;
		std::cout	<< "ScavTrap "	<< m_name
					<< " is now in Idle mode." << std::endl;
	}
}
