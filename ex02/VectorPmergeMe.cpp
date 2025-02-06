/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/06 12:30:19 by nmihaile         ###   ########.fr       */
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
			std::swap(*first, *second);
		return (sorted);
	}

	// lets build pairs
	size_t	pairCount = itemsCount / 2;
	std::vector<std::pair<Item, Item>>	pairs;
	for (size_t i = 0; i < pairCount; ++i)
	{
		auto curr = input.begin() + i * 2;
		auto next = std::next(curr);
		if (curr->value > next->value)
			pairs.push_back({*curr, *next});
		else
			pairs.push_back({*next, *curr});
	}

	// lets catch the winners
	
	
	return (m_container);
}
