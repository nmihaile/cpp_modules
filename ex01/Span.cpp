/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:23:07 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/18 16:36:29 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : m_capacity(n), m_size(0), m_items(nullptr)
{
	if (m_capacity > 0)
		m_items = new int[m_capacity]();
}

Span::~Span()
{
	if (m_items)
		delete[](m_items);
}


/* ************************************************************************** */
/* ************************************************************************** */


Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		if (m_items)
			delete[](m_items);
		m_capacity = rhs.m_capacity;
		m_size = rhs.m_size;

		if (m_capacity > 0)
		{
			m_items = new int[m_capacity];
			for (unsigned int i = 0; i < m_size; ++i)
				m_items[i] = rhs.m_items[i];
		}
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (m_size >= m_capacity)
		throw ( std::overflow_error("Span has reached its capacity, cannot add more elements.") );
	m_items[m_size++] = n;
}

unsigned int	Span::shortesSpan(void)
{
	if (m_size <= 1)
		throw ( std::logic_error("Not enough elements to calculate a span.") );

	unsigned int	sp = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 1; i < m_size; ++i)
	{
		unsigned int diff = (m_items[i] > m_items[i - 1])
							? (m_items[i] - m_items[i - 1])
							: (m_items[i - 1] - m_items[i]);
		if (diff < sp)
			sp = diff;
	}
	
	return (sp);
}

