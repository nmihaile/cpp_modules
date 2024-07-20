/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:35:27 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/20 15:02:23 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Tom("Tom");
	ClapTrap Tom2(Tom);
	ClapTrap Tom3;
	Tom3 = Tom2;
	

	// Basic test
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
