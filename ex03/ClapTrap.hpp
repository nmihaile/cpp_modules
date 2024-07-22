/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:35:53 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/22 20:10:03 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>


/* 
DiamondTrap
attribute
Claptrap:name claptrapname -> Scav -> Fragtrap
Claptrap:hitpoints claptvalue ->Scav -> frag
Claptrap:attack clapvalue -> scav -> frag
Claptrap:energypoints clapenergy -> Scavtrap:Energypoints -> frag(Claptrap->energy)  
 */

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	status(void);

	std::string		get_name(void);
	unsigned int	get_hit_points(void);
	unsigned int	get_energy_points(void);
	unsigned int	get_attack_damage(void);

	ClapTrap&	operator = (const ClapTrap& other);

protected:
	std::string		m_name;
	unsigned int	m_hit_points;
	unsigned int	m_energy_points;
	unsigned int	m_attack_damage;

	bool	is_dead(const std::string action);
	bool	out_of_energy(const std::string action);
};

#endif
