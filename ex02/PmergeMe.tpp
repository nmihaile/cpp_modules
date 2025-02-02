/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:35:50 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/02 16:24:36 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe()
{
}

template <typename Container>
PmergeMe<Container>::~PmergeMe()
{
}


/* ************************************************************************** */
/* ************************************************************************** */

template <typename Container>
void	PmergeMe<Container>::parseArguments(int ac, char **av)
{
	for (int i = 0; i < ac; ++i)
	{
		validateIntStr(av[i]);
		
		unsigned int		value;
		std::stringstream	ss(av[i]);

		ss >> value;
		if (ss.fail())
			throw ( std::invalid_argument("Failed to convert argument into unsigned int: " + std::string(av[i])) );

		m_container.push_back(value);
		std::cout << value << " ";
	}
}

template <typename Container>
void	PmergeMe<Container>::sort()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


template <typename Container>
void	PmergeMe<Container>::validateIntStr(std::string str)
{
	for (std::string::iterator it = str.begin(); it < str.end() ; ++it)
		if (!std::isdigit(*it))
			throw ( std::invalid_argument("Invalid character in argument: " + str) );
}
