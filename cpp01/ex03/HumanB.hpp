/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:27:59 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/08 12:46:28 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
#define HumanB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon *weapon);
	~HumanB();

	void	attack(void);
	void	setWeapon(Weapon &weapon);

private:
	std::string	m_name;
	Weapon		*m_weapon;
};

#endif
