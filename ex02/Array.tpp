/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:10:32 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/14 16:33:16 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
class Array
{
public:
	Array() : m_items(nullptr), m_count(0), m_capacity(0), m_allocator(std::allocator<T>()) {
	}

	Array(unsigned int n) : m_items(nullptr), m_count(n), m_capacity(0) {
	}

	Array(const Array& other)
		:	m_items(new T[other.m_capacity]),
			m_count(other.m_count),
			m_capacity(other.m_capacity) {
	}

	~Array() {
		free_items();
	}

	Array&	operator=(const Array& rhs) {
		if (this != &rhs)
		{
			free_items();
			m_items		= new T[rhs.m_capacity];
			m_count		= rhs.m_count;
			m_capacity	= rhs.m_capacity;
			for (unsigned int it = 0; it < m_count; ++it)
				m_items[it] = rhs.m_items[it];
		}
	}

private:
	T*					m_items;
	unsigned int		m_count;
	unsigned int		m_capacity;
	std::allocator<T>	m_allocator;

	void	free_items(void) {
		if (m_items)
		{
			delete(m_items);
			m_items		= nullptr;
			m_count		= 0;
			m_capacity	= 0;
		}
	}
};
