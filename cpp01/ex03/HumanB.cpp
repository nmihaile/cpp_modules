/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:27:57 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/09 15:20:16 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL)
{
}

HumanB::HumanB(std::string name, Weapon *weapon) : m_name(name), m_weapon(weapon)
{
}

HumanB::~HumanB()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


void	HumanB::setWeapon(Weapon &weapon)
{
	m_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (m_weapon == NULL || m_weapon->getType().compare("") == 0)
		std::cout << m_name << " with no weapon " << std::endl;
	else
		std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}
