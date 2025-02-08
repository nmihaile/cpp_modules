/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:35:50 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/08 12:42:27 by nmihaile         ###   ########.fr       */
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

template <typename Container>
void	PmergeMe<Container>::sort(void)
{
	m_compairisons = 0;
	m_container = merge_insert(m_container);
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
void	PmergeMe<Container>::print(std::string prefix, bool check)
{
	bool is_sorted = isSorted();

	std::cout << "\033[95m" << std::setw(6) << std::left << prefix << ": \033[0m";

	if (is_sorted)
		std::cout << "\033[92m";

	if (m_container.size() < 22)
		for (auto& item : m_container)
			std::cout << std::setw(2) << item.value << " ";
	else
		std::cout	<< std::setw(6) << (*m_container.begin()).value << " ... "
					<< std::setw(0) << m_container.back().value << " ";

	if (check)
		(is_sorted)	? std::cout << "✅ " << "\033[96m" << std::setw(5) << std::right << m_compairisons << "\033[95m [" << m_container.size() << "]\033[0m" 
					: std::cout << "❌ " << "\033[96m" << std::setw(5) << std::right << m_compairisons << "\033[95m [" << m_container.size() << "]\033[0m";
	std::cout << std::endl;
}

template <typename Container>
bool	PmergeMe<Container>::cmp(const unsigned int& a, const unsigned int& b)
{
	++m_compairisons;
	return (a < b);
}

template <typename Container>
Container	PmergeMe<Container>::insertOrder(size_t count)
{
	Container	seq;

	if (count == 0)
		return (seq);
	if (count == 1)
		return (seq.push_back({0, 0}), seq);

	unsigned int jac_n = 3;
	unsigned int highest = 1;
	while (seq.size() < count)
	{
		unsigned int	pow2n = 1 << jac_n;
		int				powNeg1n = (jac_n++ % 2 == 0) ? 1 : -1;
		unsigned int	jac = (pow2n - powNeg1n) / 3;

		if ( jac - highest > count - seq.size() )
		{
			size_t idx = seq.size();
			while (seq.size() < count)
			{
				++highest;
				seq.push_back({highest, highest});
			}
			std::reverse(seq.begin() + idx, seq.end());
			return (seq);
		}

		unsigned int val = jac;
		while (val > highest)
		{
			seq.push_back({val, val});
			--val;
			if (seq.size() >= count)
				return (seq);
		}
		highest = jac;
	}

	return (seq);
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
