/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:23:08 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/18 15:29:59 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
public:
	Span(unsigned int n);
	~Span();

	Span&	operator=(const Span& rhs);
	
private:
	Span() = delete;
	Span(const Span& other) = delete;
	
	unsigned int	m_capacity;
	int*			m_items;
};

#endif
