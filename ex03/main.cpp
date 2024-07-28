/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:18:49 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 19:19:32 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#define LIGHTGRAY		"\033[97m"
#define DARKBLACK		"\033[90m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTYELLOW		"\033[93m"
#define LIGHTBLUE		"\033[94m"
#define LIGHTMAGENTA	"\033[95m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

void	pmsg(std::string msg, std::string color)
{
	std::cout << color << msg << RESET << std::endl;
}

void	custom_tests(void)
{
	pmsg("[ TEST ] › Character equip", LIGHTCYAN);
	Character player("Mario");
	Character enemie("Goomba");

	player.equip(new Ice());
	player.equip(new Cure());

	pmsg("[ TEST ] › Character use", LIGHTCYAN);
	player.use(0, enemie);
	player.use(1, enemie);
	player.use(2, enemie);
	player.use(3, enemie);
	player.use(-1, enemie);
	player.use(5, enemie);

	pmsg("[ TEST ] › Character more equip", LIGHTCYAN);
	player.equip(new Ice());
	player.equip(new Cure());
	player.use(2, enemie);
	player.use(3, enemie);

	player.equip(new Ice());
	player.equip(new Cure());

	pmsg("[ TEST ] › Character unequip", LIGHTCYAN);
	player.unequip(1);
	player.unequip(3);

	player.equip(new Ice());
	player.equip(new Cure());


	pmsg("[ TEST ] › MateriaSources", LIGHTCYAN);

	IMateriaSource* src = new MateriaSource();

	player.unequip(0);
	player.unequip(1);
	player.unequip(2);
	player.unequip(3);

	player.equip(src->createMateria("ice"));
	player.equip(src->createMateria("cure"));

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(NULL);

	player.equip(src->createMateria("ice"));
	player.equip(src->createMateria("cure"));
	player.equip(src->createMateria("fire"));
	player.equip(src->createMateria(""));

	player.use(0, enemie);
	player.use(1, enemie);
	player.use(2, enemie);
	player.use(3, enemie);

	delete (src);

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

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	return (0);
}
