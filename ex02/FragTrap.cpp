/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:57:46 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/21 11:01:08 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Undefined", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called: " << this->m_name << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap name constructor called: " << m_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called: " << other.m_name << std::endl;

	this->copy_member_vars(other);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called: " << m_name << std::endl;
}


/* ************************************************************************** */
/* ************************************************************************** */


void	FragTrap::highFivesGuys(void)
{
	std::cout	<< "FragTrap "	<< m_name
				<< " requests a high 5!" << std::endl;
}

FragTrap&	FragTrap::operator = (const FragTrap& other)
{
	std::cout << "FragTrap copy assignement operator overload called: " << m_name << " = " << other.m_name << std::endl;

	if (this != &other)
		this->copy_member_vars(other);
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	FragTrap::init(void)
{
	m_hit_points	= 100;
	m_energy_points	= 100;
	m_attack_damage	= 30;
}
