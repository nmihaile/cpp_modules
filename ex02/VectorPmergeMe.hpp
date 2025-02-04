/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorPmergeMe.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/04 09:53:22 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VECTORPMERGEME_HPP
#define VECTORPMERGEME_HPP

#include <vector>
#include "PmergeMe.hpp"

#include <iomanip>
#include "TailwindcssColors.h"

class VectorPmergeMe : public PmergeMe<std::vector<unsigned int>>
{
public:
	VectorPmergeMe();
	VectorPmergeMe(const VectorPmergeMe& other) = delete;
	~VectorPmergeMe();

	VectorPmergeMe&	operator=(const VectorPmergeMe& rhs) = delete;

	virtual void	sort() override;

private:
	virtual void	sort(size_t	order) override;

	void			print(size_t order);
};

#endif
