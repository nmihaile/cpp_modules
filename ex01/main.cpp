/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:39:01 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/07 19:04:12 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

# define LIGHTRED		"\033[0;91m"
# define LIGHTGREEN		"\033[0;92m"
# define LIGHTYELLOW	"\033[0;93m"
# define LIGHTBLUE		"\033[0;94m"
# define LIGHTMAGENTA	"\033[0;95m"
# define LIGHTCYAN		"\033[0;96m"
# define RESET			"\033[0m"

#define ZombieCount 5

void	print_section(std::string title, std::string color)
{
	std::cout	<< color
				<< "\n--------------------------------\n"
				<< title
				<< "\n--------------------------------" << RESET << std::endl;	
}

int	main(void)
{
	Zombie *zHord;

	print_section("Create zombie hord", LIGHTGREEN);
	zHord = zombieHorde(ZombieCount, "Hungry Hannah");

	if (zHord == NULL)
		std::cout << "Error: memory for zombieHord could not be allocated." << std::endl;
	else
	{
		print_section("Announce zombie hord", LIGHTCYAN);
		for (int i = 0; i < ZombieCount; i++)
			zHord[i].announce();
		print_section("Delete zombie hord", LIGHTRED);
		delete[](zHord);
	}

	return (0);
}
