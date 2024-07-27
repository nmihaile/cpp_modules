/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:44:46 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/27 11:20:51 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#include <sstream>
#include <string>
#include <cstring>

#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTYELLOW		"\033[93m"
#define LIGHTBLUE		"\033[94m"
#define LIGHTMAGENTA	"\033[95m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

static void	msg(std::string msg, std::string color)
{
	std::cout << color << msg << RESET << std::endl;
}

void	custom_tests(void)
{
	msg("[ TEST 1 ] › default constructor", LIGHTCYAN);
	Dog dog1;
	Cat	cat1;
	std::cout << "---------------------------------------" << std::endl;

	msg("[ TEST 2 ] › copy constructor", LIGHTCYAN);
	Dog dog2(dog1);
	Cat	cat2(cat1);
	std::cout << "---------------------------------------" << std::endl;

	msg("[ TEST 3 ] › copy assignement operator", LIGHTCYAN);
	Dog dog3;
	dog3 = dog1;
	Cat	cat3;
	cat3 = cat1;
	std::cout << "---------------------------------------" << std::endl;

	msg("[ TEST 4 ] › Brain class ADDR checks", LIGHTCYAN);
	std::cout << "Dog 1 Brain addr: " << (void *)(&dog1.getBrain()) << std::hex << std::endl;
	std::cout << "Dog 2 Brain addr: " << (void *)(&dog2.getBrain()) << std::hex << std::endl;
	std::cout << "Dog 3 Brain addr: " << (void *)(&dog3.getBrain()) << std::hex << std::endl;
	std::cout << "--" << std::endl;
	std::cout << "Cat 1 Brain addr: " << (void *)(&cat1.getBrain()) << std::hex << std::endl;
	std::cout << "Cat 2 Brain addr: " << (void *)(&cat2.getBrain()) << std::hex << std::endl;
	std::cout << "Cat 3 Brain addr: " << (void *)(&cat3.getBrain()) << std::hex << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	msg("[ TEST 5 ] › Brain class deep_copy test", LIGHTCYAN);
	for (int it = 0; it < MAX_IDEAS; it++)
	{
		std::stringstream ss;
		ss << it;
		dog1.getBrain()->add_idea(std::string("Idea #" + ss.str()));
	}
	dog1.getBrain()->add_idea("I wonder what's on the other side of the door?");
	dog1.getBrain()->add_idea("I'm hungry, where's my food?");
	dog1.getBrain()->add_idea("I want to play fetch with my favorite ball!");
	dog1.getBrain()->add_idea("I need to protect my family from that stranger!");
	dog1.getBrain()->add_idea("I'm going to dig up that yard to find a bone!");
	dog2 = dog1;
	std::cout << "Dog 1 brain idea 5: " << dog1.getBrain()->ideas[4] << std::endl;
    std::cout << "Dog 2 brain idea 5: " << dog2.getBrain()->ideas[4] << std::endl;
	int r = 0;
	for (int it = 0; it < MAX_IDEAS; it++)
		if (strcmp(dog1.getBrain()->ideas[it].c_str(), dog2.getBrain()->ideas[it].c_str()) == 0)
			r++;
	if (r == 100)
		std::cout << LIGHTGREEN << "[ok]" << RESET << " 100 DOG-Ideas are the same" << std::endl;
	else
		std::cout << LIGHTRED << "[ko]" << RESET << " only " << r << " DOG-Ideas are the same" << std::endl;

	for (int it = 0; it < MAX_IDEAS; it++)
	{
		std::stringstream ss;
		ss << it;
		cat1.getBrain()->add_idea(std::string("Idea #" + ss.str()));
	}
	cat1.getBrain()->add_idea("I'm going to nap in that sunbeam!");
	cat1.getBrain()->add_idea("I want to chase that laser pointer!");
	cat1.getBrain()->add_idea("I'm going to scratch that furniture to mark my territory!");
	cat1.getBrain()->add_idea("I need to groom myself to look my best!");
	cat1.getBrain()->add_idea("I'm going to hide in that box and surprise my human!");
	cat2 = cat1;
	std::cout << "Cat 1 brain idea 5: " << cat1.getBrain()->ideas[4] << std::endl;
    std::cout << "Cat 2 brain idea 5: " << cat2.getBrain()->ideas[4] << std::endl;
	r = 0;
	for (int it = 0; it < MAX_IDEAS; it++)
		if (strcmp(cat1.getBrain()->ideas[it].c_str(), cat2.getBrain()->ideas[it].c_str()) == 0)
			r++;
	if (r == 100)
		std::cout << LIGHTGREEN << "[ok]" << RESET << " 100 CAT-Ideas are the same" << std::endl;
	else
		std::cout << LIGHTRED << "[ko]" << RESET << " only " << r << " CAT-Ideas are the same" << std::endl;
	std::cout << "---------------------------------------" << std::endl;


	// RENDER ALL IDEAS OF DOG1
	// for (int it = 0; it < MAX_IDEAS; it++)
	// 	std::cout << dog1.getBrain()->ideas[it] << "\n";
	// std::cout << std::endl;

}

int	main(int ac, char **av)
{
	if (ac > 1)
		return ((void)av, custom_tests(), 0);
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* l = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	l->makeSound();
	meta->makeSound();
	
	delete(l);
	delete(i);
	delete(j);
	delete(meta);

	return (0);
}
