/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:01 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/04 10:14:00 by nmihaile         ###   ########.fr       */
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
	sort(1);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	VectorPmergeMe::sort(size_t	order)
{
	print(order);
	if (order > m_container.size() / 2)
	{
		std::cout << std::endl;
		return ;
	}

	for (std::vector<unsigned int>::iterator it = m_container.begin() + order - 1; it < m_container.end(); it += order * 2)
	{
		std::vector<unsigned int>::iterator next = it + order;
		if (next > m_container.end() - order)
			break ;

		if (*it > *next)
			for (int i = order - 1; i >= 0; --i)
				std::swap<unsigned int>(*(it - i), *(next - i));
	}

	sort(order * 2);

	if (m_container.size() / order <= 2)
		return ;
	std::cout << order << " | " << m_container.size() / order << std::endl;
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
