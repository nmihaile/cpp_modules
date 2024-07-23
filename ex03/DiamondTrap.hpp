/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:22:04 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/23 16:33:42 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/* 
DIAMOND_TRAP PARENT CLASS INITIALISATION FLOW

ClapTrap:name			|>>		ClapTrap(name) -> ScavTrap(sets ClapTrap->name) -> FragTrap(sets ClapTrap->name)
ClapTrap:hitpoints		|>>		ClapTrap(hitpoints) -> ScavTrap(sets ClapTrap->hitpoints) -> FragTrap(sets clapTrap->hitpoints)
THIS LINE IS THE IMPORTANT PART:
ClapTrap:energypoints	|>>		ClapTrap(energyP) -> ScavTrap(sets its own energyPoints) -> frag(sets ClapTrap->energyP)
ClapTrap:attackD		|>>		ClapTrap(attackD) -> ScavTrap(sets ClapTrap->attackD) -> FragTrap(sets ClapTrap->attackD)
*/

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();

	DiamondTrap&	operator = (const DiamondTrap& other);

	void			attack(const std::string& target);
	void			whoAmI(void);

private:
	std::string	m_name;
};

#endif
