/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/06 10:59:46 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VECTORPMERGEME_HPP
#define VECTORPMERGEME_HPP

#include <vector>
#include "PmergeMe.hpp"

#include <iomanip>

class VectorPmergeMe : public PmergeMe<std::vector<unsigned int>>
{
public:
	VectorPmergeMe();
	VectorPmergeMe(const VectorPmergeMe& other) = delete;
	~VectorPmergeMe();

	VectorPmergeMe&	operator=(const VectorPmergeMe& rhs) = delete;

	virtual void	sort(void) override;

private:
	virtual std::vector<unsigned int>	merge_insert(const std::vector<unsigned int>& input) override;

	void			print(size_t order);
};

#endif
