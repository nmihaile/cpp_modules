/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/08 17:45:16 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VECTORPMERGEME_HPP
#define VECTORPMERGEME_HPP

#include <algorithm>
#include <vector>
#include <utility>
#include "PmergeMe.hpp"


class VectorPmergeMe : public PmergeMe<std::vector<Item>>
{
public:
	VectorPmergeMe();
	VectorPmergeMe(const VectorPmergeMe& other) = delete;
	~VectorPmergeMe();

	VectorPmergeMe&	operator=(const VectorPmergeMe& rhs) = delete;

private:
	virtual std::vector<Item>	merge_insert(std::vector<Item> input) override;
};

#endif
