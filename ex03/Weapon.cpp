/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:05:51 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/08 12:54:50 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	m_type = "";
}

Weapon::Weapon(const std::string type) : m_type(type)
{	
}

Weapon::~Weapon(void)
{	
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Weapon::setType(const std::string type)
{
	m_type = type;
}

const std::string	Weapon::getType(void)
{
	return (m_type);
}
