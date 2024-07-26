/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:09:47 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 14:02:56 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& other);
	~Cat();

	Cat& operator = (const Cat& other);

	void	makeSound(void);
};

#endif
