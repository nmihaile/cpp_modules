/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/06 18:30:18 by nmihaile         ###   ########.fr       */
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
	m_compairisons = 0;
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
		// if (first->value > second->value)
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
		// if (curr->value > next->value)
		if ( cmp(next->value, curr->value) )
			pairs.emplace_back(std::pair<Item, Item>(*curr, *next));
		else
			pairs.emplace_back(std::pair<Item, Item>(*next, *curr));
		pairs.back().first.pidx = i;
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

	// insert the remaining b's
	// TODO: select el to insert by Jacobsthal seq, kinda
	// std::cout << "-insert winners- " << winners.size() << std::endl;
	for (auto it = winners.begin() + 1; it < winners.end(); ++it)
	{
		auto& curr_b = pairs[it->pidx].second;

		// is this right ?? or can I find a better solution
		auto bound_it = main.end() - 1;

		auto pos = std::lower_bound(main.begin(), bound_it, curr_b.value,
			[this](const Item& el, unsigned int val){
				// std::cout << "el: " << el.value << " | val: " << val << "\n";
				++this->m_compairisons;
				return (el.value < val);
			});
		main.insert(pos, curr_b);
	}

	// dont forget about the odd el at the end
	// std::cout << "-insert odd- " << std::endl;
	if (itemsCount % 2 == 1)
	{
		auto leftover = input.back();
		auto pos = std::lower_bound(main.begin(), main.end(), leftover.value,
			[this](const Item& el, unsigned int val){
				// std::cout << "el: " << el.value << " . val: " << val << "\n";
				++this->m_compairisons;
				return (el.value < val);
			});
		main.insert(pos, leftover);
	}

	// std::cout << "---------------" << std::endl;
	return (main);
}
