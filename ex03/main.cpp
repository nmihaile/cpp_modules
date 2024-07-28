/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:18:49 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 15:28:12 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main(void)
{
		
	// Ice *ice = new Ice();
	// Cure *cure; = 
	Character player("Mario");
	Character enemie("Goomba");

	Character *e = new Character("NULLY");
	delete(e);

	player.equip(new Ice());
	player.equip(new Cure());
	player.use(0, enemie);
	player.use(1, enemie);
	player.use(2, enemie);
	player.use(3, enemie);
	player.use(-1, enemie);
	player.use(5, enemie);

	player.use(0, *e);

	return (0);
}
