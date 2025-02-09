/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListPmergeMe.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:17:04 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/09 19:41:22 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListPmergeMe.hpp"

ListPmergeMe::ListPmergeMe() : PmergeMe("std::list")
{
}

ListPmergeMe::~ListPmergeMe()
{
}



/* ************************************************************************** */
/* ************************************************************************** */


std::list<Item>	ListPmergeMe::merge_insert(std::list<Item> input)
{
	const size_t	inputSize = input.size();

	if (inputSize <= 1)
		return (input);
	
	if (inputSize == 2)
	{
		if (cmp(input.back().value, input.begin()->value))
			std::swap(*input.begin(), input.back());
		return (input);
	}

	// lets build pairs and winners at the same time
	const size_t	pairCount = inputSize / 2;
	std::list<std::pair<Item, Item>>	pairs;
	std::list<Item>						winners;

	auto it = input.begin();
	for (size_t i = 0; i < pairCount; ++i)
	{
		const auto curr = it;
		const auto next = std::next(curr);
		if ( cmp(next->value, curr->value) )
		{
			pairs.emplace_back(std::pair<Item, Item>(*curr, *next));
			winners.emplace_back(*curr);
		}
		else
		{
			pairs.emplace_back(std::pair<Item, Item>(*next, *curr));
			winners.emplace_back(*next);
		}
		it = std::next(curr, 2);
	}

	return (input);
}
