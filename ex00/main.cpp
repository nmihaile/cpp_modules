/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:39:01 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/07 17:56:03 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *z1;
	Zombie *z2;

	std::cout	<< "--------------------------------\n"
				<< "Zombies on HEAP:\n"
				<< "--------------------------------" << std::endl;
	z1 = newZombie("Heapy Graveyard Gorge");
	z2 = newZombie("Heapy Moaning Martha");
	z1->announce();
	z2->announce();
	delete(z1);
	delete(z2);
	
	std::cout	<< "\n--------------------------------\n"
				<< "Zombies on stack:\n"
				<< "--------------------------------" << std::endl;
	randomChump("Stacky Hungry Howie");
	randomChump("Stacky Toothless Terry");

	return (0);
}
