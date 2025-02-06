/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:53:26 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/06 17:41:47 by nmihaile         ###   ########.fr       */
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
#include <limits>

typedef struct s_item
{
	unsigned int	value;
	size_t			id;
	size_t			pidx;	// index of winning item in pairs
}	Item;

template <typename Container = std::vector<Item>>
class PmergeMe
{
public:


	PmergeMe();
	PmergeMe(const PmergeMe& other) = delete;
	~PmergeMe();

	PmergeMe&		operator=(const PmergeMe& rhs) = delete;

	void			parseArguments(int ac, char **av);
	virtual void	sort(void) = 0;

	void			print(bool check);

protected:
	Container	m_container;

	void				validateIntStr(std::string str);
	virtual Container	merge_insert(const Container& input) = 0;
	bool				isSorted(void);
};

#include "PmergeMe.tpp"

#endif
