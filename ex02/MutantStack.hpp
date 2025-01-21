/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:17:32 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/21 15:34:24 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template <typename T, class MutantContainer = std::deque<T>>
class MutantStack : public std::stack<T, MutantContainer>
{
public:
	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();

	MutantStack&	operator=(const MutantStack& rhs);

	typedef typename MutantContainer::iterator					iterator;
	typedef typename MutantContainer::reverse_iterator			reverse_iterator;
	typedef typename MutantContainer::const_iterator			const_iterator;
	typedef typename MutantContainer::const_reverse_iterator	const_reverse_iterator;

	iterator				begin();
	iterator				end();
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_iterator			cbegin();
	const_iterator			cend();
	const_reverse_iterator	crbegin();
	const_reverse_iterator	crend();

private:
};

#include "MutantStack.tpp"

#endif
