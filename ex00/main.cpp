/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:44:46 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 15:58:23 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	custom_tests(void)
{
	Animal	animal;
	animal.makeSound();
	Animal a2(animal);
	a2.makeSound();
	Animal a3;
	a3 = animal;
	a3.makeSound();
	std::cout << "-------------" << std::endl;

	Dog dog;
	dog.makeSound();
	Dog d2(dog);
	d2.makeSound();
	Dog d3;
	d3 = dog;
	d3.makeSound();
	std::cout << "-------------" << std::endl;

	Cat cat;
	cat.makeSound();
	Cat c2(cat);
	c2.makeSound();
	Cat c3;
	c3 = cat;
	c3.makeSound();
	std::cout << "-------------" << std::endl;

	WrongCat wcat;
	wcat.makeSound();
	WrongCat wc2(wcat);
	wc2.makeSound();
	WrongCat wc3;
	wc3 = wcat;
	wc3.makeSound();
	std::cout << "-------------" << std::endl;
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
	delete(j);
	delete(j);
	delete(meta);

	return (0);
}
