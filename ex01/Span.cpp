/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:23:07 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/19 21:08:22 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : m_capacity(n)
{
	m_vec.reserve(n);
}

Span::Span(const Span& other) : m_capacity(other.m_capacity), m_vec(other.m_vec)
{
}

Span::~Span()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		m_capacity = rhs.m_capacity;
		m_vec.reserve(m_capacity);
		m_vec = rhs.m_vec;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (m_vec.size() >= m_capacity)
		throw ( std::overflow_error("Span has reached its capacity, cannot add more elements.") );
	m_vec.emplace_back(n);
}

unsigned int	Span::shortestSpan(void)
{
	if (m_vec.size() <= 1)
		throw ( std::logic_error("Not enough elements to calculate a span.") );

	std::vector<int>	sorted = m_vec;
	std::sort(sorted.begin(), sorted.end());

	std::vector<unsigned int>	diffs(sorted.size() - 1);
	std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());
	
	return (*std::min_element(diffs.begin(), diffs.end()));
}

unsigned int	Span::longestSpan(void) const
{
	if (m_vec.size() <= 1)
		throw ( std::logic_error("Not enough elements to calculate a span.") );

	std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> bounds = std::minmax_element(m_vec.begin(), m_vec.end());
	return ( *bounds.second - *bounds.first );
}
