/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:23:08 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/18 16:36:19 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <limits>

class Span
{
public:
	Span(unsigned int n);
	~Span();

	Span&			operator=(const Span& rhs);
	void			addNumber(int n);
	unsigned int	shortesSpan(void);
	
private:
	Span() = delete;
	Span(const Span& other) = delete;
	
	unsigned int	m_capacity;
	unsigned int	m_size;
	int*			m_items;
};

#endif
