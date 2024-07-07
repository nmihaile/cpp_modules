/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:33:41 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/07 19:40:10 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : m_name("Unnamed Zombie")
{
	#ifdef DEBUG_INFO
	std::cout << "created: " << m_name << std::endl;
	#endif
}

Zombie::Zombie(std::string name) : m_name(name)
{
	#ifdef DEBUG_INFO
	std::cout << "created: " << m_name << std::endl;
	#endif
}

Zombie::~Zombie(void)
{	
	#ifdef DEBUG_INFO
	std::cout << m_name << ": deleted" << std::endl;
	#endif
}

void	Zombie::set_name(std::string new_name)
{
	m_name = new_name;
}


void	Zombie::announce(void)
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
