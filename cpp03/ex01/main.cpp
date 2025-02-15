/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:35:27 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/20 20:33:57 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap Tom("Tom");
	ClapTrap Tom2(Tom);
	ClapTrap Tom3;
	Tom3 = Tom2;

	
	std::cout << "--------------------------------------------------" << std::endl;
	Tom.status();
	
	std::cout << "--------------------------------------------------" << std::endl;
	ScavTrap Jerry("Jerry");
	Jerry.status();
	std::cout << "--------------------------------------------------" << std::endl;
	
	Jerry.guardGate(15);

	Jerry.attack("Tom");
	Jerry.takeDamage(15);
	
	Jerry.guardGate(0);

	Jerry.takeDamage(233);
	Jerry.guardGate(14);


	// Basic test
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	Tom.attack("Jerry");
	Tom.takeDamage(3);
	Tom.beRepaired(3);

	// Run out of ENERGY_POINTS and test
	// attack
	// beRepaired
	for (int i = 0; i < 9; i++)
		Tom.attack("Jerry");
	Tom.beRepaired(10);

	// Run out of HIT_POINTS …
	Tom.takeDamage(5);
	Tom.takeDamage(7);

	// … and test all actions
	Tom.attack("Jerry");
	Tom.takeDamage(10);
	Tom.beRepaired(10);
	
		
	return (0);
}
