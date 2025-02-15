/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:10:30 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 21:13:11 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : m_name("undefined_character"), m_didx(0)
{
	log(DEBUG_LOG, "Character default constructor called.");

	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		m_inventory[idx] = NULL;
		m_droped_inv[idx] = NULL;
	}
}

Character::Character(std::string name) : m_name(name), m_didx(0)
{
	log(DEBUG_LOG, "Character name constructor called.");

	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		m_inventory[idx] = NULL;	
		m_droped_inv[idx] = NULL;
	}
}

Character::Character(const Character& other) : m_name(other.m_name), m_didx(0)
{
	log(DEBUG_LOG, "Character copy constructor called.");

	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		if (other.m_inventory[idx])
			m_inventory[idx] = other.m_inventory[idx]->clone();
		else
			m_inventory[idx] = NULL;
		m_droped_inv[idx] = NULL;
	}
}

Character::~Character()
{
	log(DEBUG_LOG, "Character destructor called.");

	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		if (m_inventory[idx])
			delete(m_inventory[idx]);
		if (m_droped_inv[idx])
			delete(m_droped_inv[idx]);
	}
}


Character&	Character::operator = (const Character& other)
{
	log(DEBUG_LOG, "Character copy assignement operator overload called.");

	if (this == &other)
		return (*this);

	m_name = other.m_name;
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
	{
		if (m_inventory[idx])
			this->drop(m_inventory[idx]);
		if (other.m_inventory[idx])
			m_inventory[idx] = other.m_inventory[idx]->clone();
		else
			m_inventory[idx] = NULL;
	}
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


const std::string&	Character::getName() const
{
	return (m_name);
}

void	Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		log(WARNING_LOG, "Character equip failed: materia is NULL");
		return ;
	}
		
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		if (m_inventory[idx] == NULL)
		{
			log(INFO_LOG, "Character equips slot " + ft_itostring(idx) + " with " + m->getType());
			m_inventory[idx] = m;
			return ;
		}
	this->drop(m);
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < INVENTORY_SIZE && m_inventory[idx])
	{
		this->drop(m_inventory[idx]);
		m_inventory[idx] = NULL;
		log(INFO_LOG, "Character unequips slot " + ft_itostring(idx));
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INVENTORY_SIZE && m_inventory[idx])
		m_inventory[idx]->use(target);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Character::drop(AMateria *m)
{
	log(INFO_LOG, "Character drops " + m->getType());
	if (m_droped_inv[m_didx])
		delete(m_droped_inv[m_didx]);
	m_droped_inv[m_didx++] = m;
	if (m_didx >= INVENTORY_SIZE)
		m_didx = 0;
}
