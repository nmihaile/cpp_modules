/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:13:21 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/08 12:56:01 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : m_name(name), m_weapon(weapon)
{
}


/* ************************************************************************** */
/* ************************************************************************** */


void	HumanA::attack(void)
{
	std::cout << m_name << " attacks with their "	<< m_weapon.getType() << std::endl;
}
