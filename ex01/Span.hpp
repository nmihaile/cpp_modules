/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:23:08 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/19 21:45:45 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <iterator>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span& other);
	~Span();

	Span&			operator=(const Span& rhs);
	
	void			addNumber(int n);
	template <typename T>
	void			addRange(typename T::iterator first, typename T::iterator last);
	
	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void) const;
	
private:
	Span() = delete;
	
	unsigned int		m_capacity;
	std::vector<int>	m_vec;
};

#include "Span.tpp"

#endif
