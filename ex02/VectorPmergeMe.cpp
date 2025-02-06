/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/06 11:53:28 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorPmergeMe.hpp"

VectorPmergeMe::VectorPmergeMe()
{
}

VectorPmergeMe::~VectorPmergeMe()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


void	VectorPmergeMe::sort(void)
{
	m_container = merge_insert(m_container);
}


/* ************************************************************************** */
/* ************************************************************************** */


std::vector<Item>	VectorPmergeMe::merge_insert(const std::vector<Item>& input)
{
	size_t	itemsCount = input.size();

	if (itemsCount <= 1)
		return (input);
	
	if (itemsCount == 2)
	{
		std::vector<Item> sorted = input;
		std::vector<Item>::iterator first = sorted.begin();
		std::vector<Item>::iterator second = std::next(first);
		if (first->value > second->value)
			std::swap(first->value, second->value);
		return (sorted);
	}
	
	return (m_container);
}
