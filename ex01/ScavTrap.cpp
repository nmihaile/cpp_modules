/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:18:03 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/20 16:10:54 by nmihaile         ###   ########.fr       */
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

ScavTrap::ScavTrap(const ScavTrap& other)
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

void	ScavTrap::status(void)
{
	std::cout	<< "Status of ScavTrap: name: " << m_name
				<< ", hit_points: " << m_hit_points
				<< ", energy_points: " << m_energy_points
				<< ", attack_damage: " << m_attack_damage
				<< std::endl;	
}


/* ************************************************************************** */
/* ************************************************************************** */


void	ScavTrap::init(void)
{
	m_hit_points	= 100;
	m_energy_points	= 50;
	m_attack_damage	= 20;
}
