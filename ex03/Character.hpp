/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:10:31 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 20:46:31 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "debug.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define INVENTORY_SIZE 4

class Character : public ICharacter
{
public:
	Character();
	Character(std::string name);
	Character(const Character& other);
	virtual ~Character();

	Character&	operator = (const Character& other);

	virtual const std::string&	getName() const;
	virtual void				equip(AMateria *m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);

private:
	std::string	m_name;
	AMateria*	m_inventory[INVENTORY_SIZE];
	AMateria*	m_droped_inv[INVENTORY_SIZE];
	int			m_didx;

	void	drop(AMateria *m);
};

#endif
