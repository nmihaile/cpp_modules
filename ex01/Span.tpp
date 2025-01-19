/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:35:50 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/19 21:55:50 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename T>
void	Span::addRange(typename T::iterator first, typename T::iterator last)
{
	if (m_vec.size() + std::distance(first, last) > m_capacity)
		throw ( std::overflow_error("Adding this range exceeds Span capacity.") );
	std::copy(first, last, std::back_inserter(m_vec));
}
