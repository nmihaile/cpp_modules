/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/06 11:01:20 by nmihaile         ###   ########.fr       */
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
	merge_insert(m_container);
}


/* ************************************************************************** */
/* ************************************************************************** */


std::vector<unsigned int>	VectorPmergeMe::merge_insert(const std::vector<unsigned int>& input)
{
	(void)input;
	return (m_container);
}

void	VectorPmergeMe::print(size_t order)
{
	std::cout << "\033[92m[" << std::setw(2) << std::setfill('0') << std::right << order << "] ";
	int c = 0;
	for (std::vector<unsigned int>::iterator it = m_container.begin(); it < m_container.end(); ++it)
	{
		std::cout << ((c++ % 2 == 0) ? "\033[38;2;124;134;255m"
									 : "\033[38;2;152;16;250m" );
		for (size_t g = 0; g < order; ++g)
		{
			if (it + g > m_container.end() - 1)
				break ;
			std::cout << std::setw(2) << std::setfill('0') << std::right << *(it + g) << " ";
		}
		it += order - 1;
	}

	if (order > m_container.size() / 2)
		std::cout << "\033[0m" << " -  DONE";
	std::cout << std::endl;
}
