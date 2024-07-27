/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:09:49 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/27 12:17:09 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog();
	Dog(const Dog& other);
	~Dog();

	Dog&	operator = (const Dog& other);

	virtual void	makeSound(void) const;
	Brain*&	getBrain(void);
	
private:
	Brain	*m_brain;

	void	swap(Dog& other);
};

#endif
