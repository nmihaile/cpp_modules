/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/09 16:43:54 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorPmergeMe.hpp"

VectorPmergeMe::VectorPmergeMe() : PmergeMe("std::vector")
{
}

VectorPmergeMe::~VectorPmergeMe()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


std::vector<Item>	VectorPmergeMe::merge_insert(std::vector<Item> input)
{
	const size_t	inputSize = input.size();

	if (inputSize <= 1)
		return (input);
	
	if (inputSize == 2)
	{
		if (cmp(input[1].value, input[0].value))
			std::swap(input[0], input[1]);
		return (input);
	}

	// lets build pairs
	// and winners at the same time
	const size_t	pairCount = inputSize / 2;
	std::vector<std::pair<Item, Item>>	pairs;
	pairs.reserve(pairCount);

	std::vector<Item>	winners;
	winners.reserve(pairCount);

	for (size_t i = 0; i < pairCount; ++i)
	{
		const auto curr = input.begin() + i * 2;
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
	}
	
	// and recursively sort them
	winners = merge_insert(winners);

	// find b1 in pairs according to new sorted a's
	const Item b1 = [&](){
		for (auto& p : pairs)
			if (p.first.id == winners[0].id)
				return (p.second);
		return pairs[0].second;
	}();

	// create main chain and push b1 and all a's
	std::vector<Item>	main;
	main.reserve(inputSize);
	main.emplace_back(b1);
	main.insert(main.end(), winners.begin(), winners.end());

	if (inputSize % 2 == 1)
	{
		pairs.push_back({input.back(), input.back()});
		winners.emplace_back(input.back());
	}
	
	// insert the remaining b's
	if (winners.size() > 1)
	{
		bool inserting = true;

		auto highest = winners.begin();
		unsigned int jac_n = 3;

		while (inserting)
		{
			// find curr_w with curren jac
			std::vector<Item>::iterator curr_w = winners.begin() + jacobsthal(jac_n++) - 1;
			if (curr_w >= winners.end())
			{
				curr_w = winners.end() - 1;
				inserting = false;
			}

			// loop down from curr_w to highest
			auto new_highest = curr_w;
			std::vector<Item>::iterator bound_end;
			while (curr_w > highest)
			{
				// get curr_p element
				const std::vector<std::pair<Item, Item>>::iterator curr_p
					= std::find_if(pairs.begin(), pairs.end(), [&curr_w](std::pair<Item, Item> it){
						return ( it.first.id == curr_w->id );
					});

				// find bound_el in main
				const std::vector<Item>::iterator bound_end
					= (inputSize % 2 == 1 && curr_p->first.id == winners.back().id)
						?	main.end()
						:	std::find_if(main.begin(), main.end(), [&curr_p](Item item){
							return ( item.id == curr_p->first.id);
						});

				// binary insert
				const auto pos = std::lower_bound(main.begin(), bound_end, curr_p->second.value,
					[this](const Item& el, unsigned int val){
						++this->m_compairisons;
						return (el.value < val);
					});
				main.insert(pos, curr_p->second);

				--curr_w;
			}
			highest = new_highest;
		}
	}

	return (main);
}
