/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:35:50 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/06 20:22:27 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe() : m_compairisons(0)
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
	for (int i = 1; i < ac; ++i)
	{
		validateIntStr(av[i]);
		
		unsigned int		value;
		std::stringstream	ss(av[i]);

		ss >> value;
		if (ss.fail())
			throw ( std::invalid_argument("Failed to convert argument into unsigned int: " + std::string(av[i])) );

		m_container.push_back({value, static_cast<unsigned int>(i - 1)});
	}
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

template <typename Container>
void	PmergeMe<Container>::print(bool check)
{
	bool is_sorted = isSorted();

	if (is_sorted)
		std::cout << "\033[92m";

	if (m_container.size() < 35)
		for (auto& item : m_container)
			std::cout << std::setw(2) << item.value << " ";
	else
		std::cout	<< std::setw(6) << (*m_container.begin()).value << " ... "
					<< std::setw(6) << m_container.back().value << " ";

	if (check)
		(is_sorted)	? std::cout << "✅ " << "\033[96m" << m_compairisons << "\033[0m" 
					: std::cout << "❌ " << "\033[96m" << m_compairisons << "\033[0m";
	std::cout << std::endl;
}

template <typename Container>
bool	PmergeMe<Container>::cmp(const unsigned int& a, const unsigned int& b)
{
	++m_compairisons;
	return (a < b);
}

template <typename Container>
bool	PmergeMe<Container>::isSorted(void)
{
	if (m_container.size() <= 1)
		return (true);

	for (auto it = m_container.begin() + 1; it < m_container.end(); ++it)
		if (it->value < (it - 1)->value)
			return (false);

	return (true);
}
