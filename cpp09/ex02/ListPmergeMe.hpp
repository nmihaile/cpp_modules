/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListPmergeMe.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:17:06 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/09 21:38:41 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LISTPMERGEME_HPP
#define LISTPMERGEME_HPP

#include <algorithm>
#include <utility>
#include <list>
#include "PmergeMe.hpp"

class ListPmergeMe : public PmergeMe<std::list<Item>>
{
public:
	ListPmergeMe();
	ListPmergeMe(const ListPmergeMe& other) = delete;
	~ListPmergeMe();

	ListPmergeMe&	operator=(const ListPmergeMe& rhs) = delete;

private:
	virtual std::list<Item>	merge_insert(std::list<Item> input) override;
};

#endif
