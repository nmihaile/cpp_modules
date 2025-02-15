/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:09:47 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/27 12:17:35 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
public:
	Cat();
	Cat(const Cat& other);
	~Cat();

	Cat& operator = (const Cat& other);

	virtual void	makeSound(void) const;

	Brain*&	getBrain(void);

private:
	Brain	*m_brain;

	void	swap(Cat& other);
};

#endif
