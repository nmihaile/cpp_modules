/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:39:01 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/07 18:47:23 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ZombieCount 25

int	main(void)
{
	Zombie *zHord;

	std::cout	<< "--------------------------------\n"
				<< "Creates Zombie Hord (" << ZombieCount << "):\n"
				<< "--------------------------------" << std::endl;
	
	zHord = zombieHorde(ZombieCount, "Hungry Hannah");

	if (zHord == NULL)
		std::cout << "Error: memory for zombieHord could not be allocated." << std::endl;
	else
	{
		for (int i = 0; i < ZombieCount; i++)
			zHord[i].announce();
		delete[](zHord);
	}

	return (0);
}
