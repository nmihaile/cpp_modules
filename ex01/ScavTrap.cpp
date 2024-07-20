/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:18:03 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/20 21:37:34 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called: " << this->m_name << std::endl;

	this->init();
}

ScavTrap::ScavTrap(const std::string name)
{
	m_name = name;
	this->init();

	std::cout << "ScavTrap name constructor called: " << m_name << std::endl;
}

// The base 'class ClapTrap' must be explicitly initialized in the copy constructor
// because ScavTrap contains a base class subobject of type ClapTrap. 
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called: " << other.m_name << std::endl;	
	
	this->copy_member_vars(other);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called: " << m_name << std::endl;	
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

void	ScavTrap::status(void)
{
	std::cout	<< "Status of ScavTrap: name: " << m_name
				<< ", hit_points: " << m_hit_points
				<< ", energy_points: " << m_energy_points
				<< ", attack_damage: " << m_attack_damage
				<< std::endl;	
}

ScavTrap&	ScavTrap::operator = (const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignement operator overload called: " << m_name << " = " << other.m_name << std::endl;	

	if (this != &other)
		this->copy_member_vars(other);		
	return (*this);		
}


/* ************************************************************************** */
/* ************************************************************************** */


void	ScavTrap::init(void)
{
	m_state			= ST_IDLE;
	m_hit_points	= 100;
	m_energy_points	= 50;
	m_attack_damage	= 20;
	m_guardedGateID = 0;
}
