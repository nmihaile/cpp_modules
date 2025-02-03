/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/03 19:49:06 by nmihaile         ###   ########.fr       */
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


void	VectorPmergeMe::sort()
{
	print(0);
	sort(1);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	VectorPmergeMe::sort(size_t	order)
{
	if (order > m_container.size() / 2)
		return ;

	for (std::vector<unsigned int>::iterator it = m_container.begin() + order - 1; it < m_container.end(); it += order * 2)
	{
		std::vector<unsigned int>::iterator next = it + order;
		if (next > m_container.end() - order)
			break ;

		if (*it > *next)
		{
			// std::cout << "\033[91m" << "[" << *it << "]" << "[" << *next << "] ";
			for (int i = order - 1; i >= 0; --i)
				std::swap<unsigned int>(*(it - i), *(next - i));
		}
		// else
		// 	std::cout << "\033[92m" << "[" << *it << "]" << "[" << *next << "] ";
	}
	// std::cout << "\n";
	print(order);
	sort(order * 2);
}

void	VectorPmergeMe::print(size_t order)
{
	std::cout << "\033[92m[" << std::setw(2) << std::setfill('0') << std::right << order << "] ";
	int c = 0;
	for (std::vector<unsigned int>::iterator it = m_container.begin(); it < m_container.end(); ++it)
	{
		std::cout << [](size_t order, int c){
			(order == 0) ? order = 1 : order *= 2;
			if (c % (order * 2) < order)	return std::string("\033[94m");
			else							return std::string("\033[95m");
		}(order, c) << std::setw(2) << std::setfill('0') << std::right << *it << " ";
		c++;
	}
	std::cout << std::endl;
}
