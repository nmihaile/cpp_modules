/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:23:07 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/18 15:38:35 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : m_capacity(n), m_items(nullptr)
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
		if (m_capacity > 0)
		{
			m_items = new int[m_capacity];
			for (unsigned int i = 0; i < m_capacity; ++i)
				m_items[i] = rhs.m_items[i];
		}
	}
	return (*this);
}
