/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:53:26 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/03 15:16:40 by nmihaile         ###   ########.fr       */
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

template <typename Container = std::vector<unsigned int>>
class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other) = delete;
	~PmergeMe();

	PmergeMe&	operator=(const PmergeMe& rhs) = delete;

	void			parseArguments(int ac, char **av);
	virtual void	sort() = 0;

protected:
	Container	m_container;

	void			validateIntStr(std::string str);
	virtual void	sort(size_t	order) = 0;
};

#include "PmergeMe.tpp"

#endif
