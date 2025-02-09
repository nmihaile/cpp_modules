/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListPmergeMe.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:17:04 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/09 19:55:24 by nmihaile         ###   ########.fr       */
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

	// and recursively sort them
	winners = merge_insert(winners);

	// find b1 in pairs according to new sorted a's
	const Item b1 = [&](){
		for (auto& p : pairs)
			if (p.first.id == winners.begin()->id)
				return (p.second);
		return pairs.begin()->second;
	}();

	// create main chain and push b1 and all a's
	std::list<Item>	main;
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
			std::list<Item>::iterator curr_w = std::next(
				winners.begin(),
				std::min(static_cast<size_t>(jacobsthal(jac_n++) - 1), winners.size())
			);
			if (curr_w == winners.end())
			{
				curr_w = std::prev(winners.end());
				inserting = false;
			}

			// loop down from curr_w to highest
			auto new_highest = curr_w;
			std::list<Item>::iterator bound_end;
			while (curr_w != highest)
			{
				// get curr_p element
				const std::list<std::pair<Item, Item>>::iterator curr_p
					= std::find_if(pairs.begin(), pairs.end(), [&curr_w](std::pair<Item, Item> it){
						return ( it.first.id == curr_w->id );
					});

				// find bound_el in main
				const std::list<Item>::iterator bound_end
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
