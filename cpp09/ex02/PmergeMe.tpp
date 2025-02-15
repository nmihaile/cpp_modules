/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:35:50 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/10 16:07:28 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe(std::string _container_name)
	:	m_compairisons(0),
		m_sorted_count(0),
		m_container_name(_container_name),
		m_elapsed_time(0),
		m_unsorted_count(0),
		m_sorted_was_executed(false)
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
	m_unsorted_count = m_container.size();
}

template <typename Container>
void	PmergeMe<Container>::sort(void)
{
	m_compairisons = 0;
	
	std::chrono::high_resolution_clock::time_point	t1 = std::chrono::high_resolution_clock::now();

	m_container = merge_insert(m_container);
	m_sorted_count = m_container.size();
	
	std::chrono::high_resolution_clock::time_point	t2 = std::chrono::high_resolution_clock::now();
	m_elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);

	m_sorted_was_executed = true;
}

template <typename Container>
void	PmergeMe<Container>::print(std::string prefix, bool check, bool time)
{
	bool is_sorted = isSorted();

	std::cout << "\033[95m" << std::setw(6) << std::left << prefix << ": \033[0m";

	if (is_sorted)
		std::cout << "\033[92m";
	else
		std::cout << "\033[91m";

	if (m_container.size() < 22)
		for (auto& item : m_container)
			std::cout << std::setw(2) << std::right << item.value << " ";
	else
		std::cout	<< std::setw(6) << (*m_container.begin()).value << " ... "
					<< std::setw(0) << m_container.back().value << " ";

	if (check)
	{
		(is_sorted)	? std::cout << "✅ " << "\033[96m" << std::setw(5) << std::right << m_compairisons << " comp.  " << printItemCount(m_sorted_was_executed)  
					: std::cout << "❌ " << "\033[96m" << std::setw(5) << std::right << m_compairisons << " comp.  " << printItemCount(m_sorted_was_executed);
		if (time)
			std::cout << "\033[0m : \033[93m" << std::fixed << m_elapsed_time.count() / 1000000000.0 << " sec";
	}
	std::cout << "\033[0m" << std::endl;
}

template <typename Container>
void	PmergeMe<Container>::printTime()
{
	std::cout	<< "\033[96m=> Time to process a range of "
				<< "\033[95m[" << m_container.size() << "]"
				<< "\033[96m elements with "
				<< "\033[95;1m[" << std::setw(11) << std::left << m_container_name << "]"
				<< "\033[96;0m : "
				<< "\033[93m" << std::fixed << m_elapsed_time.count() / 1000000000.0 << " sec \033[0m" << std::endl;
}

template <typename Container>
double	PmergeMe<Container>::getElapsedTime()
{
	return ( m_elapsed_time.count() );
}


/* ************************************************************************** */
/* ************************************************************************** */


template <typename Container>
bool	PmergeMe<Container>::cmp(const unsigned int& a, const unsigned int& b)
{
	++m_compairisons;
	return (a < b);
}

template <typename Container>
unsigned int	PmergeMe<Container>::jacobsthal(unsigned int n)
{
	return ( ((1 << n) - (n % 2 == 0 ? 1 : -1)) / 3 );
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
bool	PmergeMe<Container>::isSorted(void)
{
	if (m_container.size() <= 1)
		return (true);

	auto prev = m_container.begin();
	auto curr = std::next(prev);
	for (; curr != m_container.end(); ++prev, ++curr)
		if (curr->value < prev->value)
			return (false);

	return (true);
}

template <typename Container>
std::string	PmergeMe<Container>::printItemCount(bool colorize_count_comparison)
{
	std::stringstream ss;

	if (colorize_count_comparison)
	{
		(m_unsorted_count == m_sorted_count)	?	ss << "\033[92m["
												:	ss << "\033[91m[";
	}
	else
		ss << "\033[95m[";
	ss << m_container.size() << "]";
	return (ss.str());
}
