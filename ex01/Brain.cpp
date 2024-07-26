/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:14:38 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 21:18:27 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : m_next_idea(0)
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


void	Brain::add_idea(std::string idea)
{
	ideas[m_next_idea++] = idea;
	if (m_next_idea >= MAX_IDEAS)
		m_next_idea = 0;
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Brain::deepcpy_ideas(const Brain& other)
{
	m_next_idea = other.m_next_idea;
	
	for (int it = 0; it < MAX_IDEAS; it++)
		ideas[it] = other.ideas[it];	
}
