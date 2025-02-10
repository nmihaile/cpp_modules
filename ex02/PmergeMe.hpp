/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:53:26 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/10 16:17:29 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <chrono>

typedef struct s_item
{
	unsigned int	value;
	size_t			id;
}	Item;

template <typename Container = std::vector<Item>>
class PmergeMe
{
public:
	PmergeMe() = delete;
	PmergeMe(std::string _container_name);
	PmergeMe(const PmergeMe& other) = delete;
	~PmergeMe();

	PmergeMe&		operator=(const PmergeMe& rhs) = delete;

	void			parseArguments(int ac, char **av);
	void			sort(void);

	void			print(std::string prefix, bool check, bool time);
	void			printTime();
	double			getElapsedTime();

protected:
	Container			m_container;
	size_t				m_compairisons;
	size_t				m_sorted_count;

	virtual Container	merge_insert(Container input) = 0;
	bool				cmp(const unsigned int& a, const unsigned int& b);
	unsigned int		jacobsthal(unsigned int n);

private:
	const std::string			m_container_name;
	std::chrono::nanoseconds	m_elapsed_time;
	size_t						m_unsorted_count;
	bool						m_sorted_was_executed;
	
	void				validateIntStr(std::string str);
	bool				isSorted(void);
	std::string			printItemCount(bool colorize_count_comparison);
};

#include "PmergeMe.tpp"

#endif
