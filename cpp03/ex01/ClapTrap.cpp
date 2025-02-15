/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:35:51 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/23 15:42:18 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:	m_name("Unnamed"),
		m_hit_points(10),
		m_energy_points(10),
		m_attack_damage(0)
{
	std::cout << "ClapTrap default constructor called: " << m_name << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
	:	m_name(name),
		m_hit_points(10),
		m_energy_points(10),
		m_attack_damage(0)	
{
	std::cout << "ClapTrap name constructor called: " << m_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	:	m_name(other.m_name),
		m_hit_points(other.m_hit_points),
		m_energy_points(other.m_energy_points),
		m_attack_damage(other.m_attack_damage)
{
	std::cout << "ClapTrap copy constructor called: " << other.m_name << std::endl;	
}

ClapTrap::~ClapTrap()
{	
	std::cout << "ClapTrap destructor called: " << m_name << std::endl;	
}

ClapTrap&	ClapTrap::operator = (const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignement operator overload called: " << m_name << " = " << other.m_name << std::endl;	

	if (this == &other)
		return (*this);
		
	m_name			= other.m_name;
	m_hit_points	= other.m_hit_points;
	m_energy_points	= other.m_energy_points;
	m_attack_damage	= other.m_attack_damage;
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	ClapTrap::attack(const std::string& target)
{
	if (this->is_dead("attack") || this->out_of_energy("attack"))
		return ;
		
	std::cout	<< "ClapTrap "	<< m_name
				<< " attacks "	<< target
				<< ", causing "	<< m_attack_damage
				<< " points of damage!" << std::endl;
	m_energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->is_dead("takeDamage"))
		return ;

	if (m_hit_points > amount)
	{
		std::cout	<< "ClapTrap "	<< m_name
					<< " takes "	<< amount
					<< " damage."	<< std::endl;

		m_hit_points -= amount;
	}
	else
	{
		std::cout	<< "ClapTrap "	<< m_name
					<< " takes "	<< m_hit_points
					<< " damage."	<< std::endl;

		m_hit_points = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->is_dead("beRepaired") || this->out_of_energy("beRepaired"))
		return ;

	std::cout	<< "ClapTrap " << m_name
				<< " repairs itself and recieves "
				<< amount << " hit points." << std::endl;

	m_hit_points += amount;
	m_energy_points--;
}

void	ClapTrap::status(void)
{
	std::cout	<< "[ STATUS ] -> name: " << m_name
				<< ", hit_points: " << m_hit_points
				<< ", energy_points: " << m_energy_points
				<< ", attack_damage: " << m_attack_damage
				<< std::endl;	
}

std::string		ClapTrap::get_name(void)			{ return (m_name); }
unsigned int	ClapTrap::get_hit_points(void)		{ return (m_hit_points); }
unsigned int	ClapTrap::get_energy_points(void)	{ return (m_energy_points); }
unsigned int	ClapTrap::get_attack_damage(void)	{ return (m_attack_damage); }


/* ************************************************************************** */
/* ************************************************************************** */


bool	ClapTrap::is_dead(const std::string action)
{
	if (m_hit_points == 0)
	{
		std::cout	<< "ClapTrap " << m_name
					<< " has no hit points left. It can't perform action: "
					<< action << std::endl;
		return (true);
	}
	return (false);
}

bool	ClapTrap::out_of_energy(const std::string action)
{
	if (m_energy_points == 0)
	{
		std::cout	<< "ClapTrap " << m_name
					<< " has no energy points left. It can't perform action: "
					<< action << std::endl;
		return (true);
	}
	return (false);	
}
