/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:35:27 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/23 16:35:10 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{

	std::cout << "\n~~{ DiamondTrap }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

	DiamondTrap dt1("D-01");
	DiamondTrap dt2;
	DiamondTrap dt3(dt1);

	std::cout << "~~" << std::endl;
	dt3.whoAmI();
	dt3.status();
	std::cout << "~~" << std::endl;


	std::cout << "~~" << std::endl;
	std::cout	<< dt1.get_name() << "\n"
				<< dt1.get_hit_points() << "\n"
				<< dt1.get_energy_points() << "\n"
				<< dt1.get_attack_damage() << std::endl;
	std::cout << "~~" << std::endl;

	dt2 = dt1;

	dt1.attack("Tom");
	dt1.takeDamage(25);
	dt1.beRepaired(7);
	dt1.highFivesGuys();
	dt2.highFivesGuys();

	
	dt1.status();
	dt2.status();

	dt1.takeDamage(150);
	dt1.highFivesGuys();

	dt1.whoAmI();
	dt2.whoAmI();
	dt3.whoAmI();

	std::cout << "\n~~{ DECONSTRUCT }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		
	return (0);
}
