/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:33:41 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/07 18:54:50 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : m_name("Unnamed Zombie")
{
	std::cout << "created: " << m_name << std::endl;
}

Zombie::Zombie(std::string name) : m_name(name)
{
}

Zombie::~Zombie(void)
{	
	std::cout << m_name << ": deleted" << std::endl;
}

void	Zombie::set_name(std::string new_name)
{
	m_name = new_name;
}


void	Zombie::announce(void)
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
