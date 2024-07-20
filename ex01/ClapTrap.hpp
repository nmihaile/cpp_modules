/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:35:53 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/20 16:08:43 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

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

	ClapTrap&	operator = (const ClapTrap& other);
	
protected:
	std::string		m_name;
	unsigned int	m_hit_points;
	unsigned int	m_energy_points;
	unsigned int	m_attack_damage;

	void	init(void);
	void	copy_member_vars(const ClapTrap& other);


	bool	is_dead(const std::string action);
	bool	out_of_energy(const std::string action);
};

#endif
