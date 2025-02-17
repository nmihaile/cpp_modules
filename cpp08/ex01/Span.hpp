/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:23:08 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/20 12:20:37 by nmihaile         ###   ########.fr       */
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
#include <limits>

class Span
{
public:
	Span(unsigned int n);
	template <typename InputIterator>
	Span(InputIterator first, InputIterator last);
	Span(const Span& other);
	~Span();

	Span&			operator=(const Span& rhs);
	
	void			addNumber(int n);
	template <typename InputIterator>
	void			addRange(InputIterator first, InputIterator last);
	
	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void) const;
	
private:
	Span() = delete;
	
	unsigned int		m_capacity;
	std::vector<int>	m_vec;
};

#include "Span.tpp"

#endif
