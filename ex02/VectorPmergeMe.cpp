/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/08 14:06:31 by nmihaile         ###   ########.fr       */
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
		if (cmp(second->value, first->value))
			std::swap(*first, *second);
		return (sorted);
	}

	// lets build pairs
	size_t	pairCount = itemsCount / 2;
	std::vector<std::pair<Item, Item>>	pairs;
	pairs.reserve(pairCount);
	for (size_t i = 0; i < pairCount; ++i)
	{
		auto curr = input.begin() + i * 2;
		auto next = std::next(curr);
		if ( cmp(next->value, curr->value) )
			pairs.emplace_back(std::pair<Item, Item>(*curr, *next));
		else
			pairs.emplace_back(std::pair<Item, Item>(*next, *curr));
	}

	// lets catch the winners
	std::vector<Item>	winners;
	winners.reserve(pairs.size());
	for (auto& p : pairs)
		winners.emplace_back(p.first);
	
	// and recursively sort them
	winners = merge_insert(winners);

	// find b1 in pairs according to new sorted a's
	Item b1 = pairs[0].second;
	for (auto& p : pairs)
		if (p.first.id == winners[0].id)
		{
			b1 = p.second;
			break ;
		}

	// create main chain and push b1 and all a's
	std::vector<Item>	main;
	main.reserve(itemsCount);
	main.emplace_back(b1);
	for (auto& a : winners)
		main.emplace_back(a);

	if (itemsCount % 2 == 1)
	{
		pairs.push_back({input.back(), input.back()});
		winners.push_back(input.back());
	}

	// insert the remaining b's
	if (winners.size() > 1)
	{
		// calc idx-seq with Jacobsthal seq
		std::vector<Item> seq = insertOrder(winners.size() - 1);

		for (auto s : seq)
		{
			unsigned int u;
			(seq.size() > 1)	? u = s.value - 2
								: u = 0;

			auto it = (winners.begin() + (1 + u)) ;
			std::pair<Item, Item> curr_p;
			for (auto& p : pairs)
				if (it->id == p.first.id)
				{
					curr_p = p;
					break ;
				}

			// find the bound el, we only have to sort in to the left of this el.
			std::vector<Item>::iterator bound_end;
			if (itemsCount % 2 == 1 && it == winners.end() - 1)
				bound_end = main.end();
			else
			{
				for (auto it = main.begin(); it < main.end(); ++it)
					if (it->id == curr_p.first.id)
					{
						bound_end = it;
						break ;
					}
			}

			auto pos = std::lower_bound(main.begin(), bound_end, curr_p.second.value,
				[this](const Item& el, unsigned int val){
					++this->m_compairisons;
					return (el.value < val);
				});
			main.insert(pos, curr_p.second);
		}
	}

	return (main);
}
