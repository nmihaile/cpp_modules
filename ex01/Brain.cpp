/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:14:38 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 18:26:10 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
}

Brain::Brain(const Brain& other)
{
	this->deepcpy_ideas(other);
}

Brain::~Brain()
{
}

Brain& Brain::operator = (const Brain& other)
{
	if (this == &other)
		return (*this);

	this->deepcpy_ideas(other);
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Brain::deepcpy_ideas(const Brain& other)
{
	for (int it = 0; it < MAX_IDEAS; it++)
		ideas[it] = other.ideas[it];	
}
