/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:35:27 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/21 10:49:01 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap Tom("Tom");
		
	std::cout << "\n~~{ ScavTrap }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	ScavTrap Jerry("Jerry");
	Jerry.status();
	
	Jerry.guardGate(15);

	Jerry.attack("Tom");
	Jerry.takeDamage(15);
	
	Jerry.guardGate(0);

	Jerry.takeDamage(233);
	Jerry.guardGate(14);


	// Basic test
	std::cout << "\n~~{ ClapTrap }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	Tom.status();
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
	
	std::cout << "\n~~{ FragTrap }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

	FragTrap ft("FortyTwo");

	ft.takeDamage(3);
	ft.beRepaired(3);

	ft.status();
	ft.highFivesGuys();

	for (int i = 0; i < 9; i++)
		ft.attack("Jerry");
	ft.beRepaired(10);
	ft.highFivesGuys();

	std::cout << "\n~~{ DECONSTRUCT }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		
	return (0);
}
