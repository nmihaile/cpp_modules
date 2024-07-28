/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:18:49 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 18:03:17 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void	custom_tests(void)
{
	Character player("Mario");
	Character enemie("Goomba");

	player.equip(new Ice());
	player.equip(new Cure());
	player.use(0, enemie);
	player.use(1, enemie);
	player.use(2, enemie);
	player.use(3, enemie);
	player.use(-1, enemie);
	player.use(5, enemie);

	player.equip(new Ice());
	player.equip(new Cure());
	player.use(2, enemie);
	player.use(3, enemie);

	player.equip(new Ice());
	player.equip(new Cure());

	player.unequip(1);
	player.unequip(3);

	player.equip(new Ice());
	player.equip(new Cure());

	// We dont have to test this, since target is a Reference
	// which should never be NULL
	// Character *e = new Character("NULLY");
	// delete(e);
	// player.use(0, *e);

}

int	main(int ac, char **av)
{
	if (ac > 1)
		return ((void)av, custom_tests(), 0);

	return (0);
}
