/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:44:46 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 15:08:03 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	custom_tests(void)
{
	Animal	animal;
	
	animal.makeSound();

	Dog dog;
	dog.makeSound();

	Cat cat;
	cat.makeSound();	
}

int	main(int ac, char **av)
{
	if (ac > 1)
		return ((void)av, custom_tests(), 0);
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();	

	return (0);
}
