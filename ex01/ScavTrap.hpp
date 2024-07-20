/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:18:05 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/20 21:37:02 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <sstream>

class ScavTrap : public ClapTrap
{
public:

	typedef enum e_state
	{
		ST_IDLE,
		ST_GATE_KEEPER
	}	t_state;

	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap();

	void		attack(const std::string& target);
	void	 	guardGate(unsigned int id);
	void		status(void);
	ScavTrap&	operator = (const ScavTrap& other);
	
private:	
	void			init(void);
	t_state			m_state;
	unsigned int	m_guardedGateID;
};

#endif
