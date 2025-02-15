/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:35:50 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/20 16:33:02 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename InputIterator>
Span::Span(InputIterator first, InputIterator last)
	:	m_capacity( static_cast<unsigned int>(std::distance(first, last)) )
{
	m_vec.reserve(m_capacity);
	addRange(first, last);
}

template <typename InputIterator>
void	Span::addRange(InputIterator first, InputIterator last)
{
	if (m_vec.size() + std::distance(first, last) > m_capacity)
		throw ( std::overflow_error("Adding this range exceeds Span capacity.") );
	if (std::distance(first, last) == 0)
		throw ( std::logic_error("Attempted to use an empty range with the Span.") );

	std::copy(first, last, std::back_inserter(m_vec));
}
