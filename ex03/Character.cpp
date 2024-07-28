/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:10:30 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 15:54:41 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : m_name("undefined_character")
{
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		m_inventory[idx] = NULL;
}

Character::Character(std::string name) : m_name(name)
{
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		m_inventory[idx] = NULL;	
}

Character::Character(const Character& other) : m_name(other.m_name)
{
	// here we have to do some clever stufff
}

Character::~Character()
{
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		if (m_inventory[idx])
			delete(m_inventory[idx]);
}


Character&	Character::operator = (const Character& other)
{
	if (this == &other)
		return (*this);

	// here we have to do some clever stufff
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
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		if (m_inventory[idx] == NULL)
		{
			m_inventory[idx] = m;
			return ;
		}
	delete(m);
}

void	Character::unequip(int idx)
{

	// What shoudl happen here wee should not delet the materia
	// I have to look what the MateriaSource-CLASS will do………

	if (idx >= 0 && idx < INVENTORY_SIZE && m_inventory[idx])
		m_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INVENTORY_SIZE && m_inventory[idx])
		m_inventory[idx]->use(target);
}

