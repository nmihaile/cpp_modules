/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:10:32 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/15 20:50:24 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	~Array();

	Array&			operator=(const Array& rhs);
	T&				operator[](const unsigned int idx);
	const T&		operator[](const unsigned int idx) const;
	unsigned int	size(void);

private:
	unsigned int	m_size;
	T*				m_items;
};


/* ************************************************************************** */
/* ************************************************************************** */


template <typename T>
Array<T>::Array() : m_size(0), m_items(nullptr)
{
}

// Here it is important to use the () after new T[n]() which call the
// default constructor of obs or inits primitive types as int and flotas to 0
template <typename T>
Array<T>::Array(unsigned int n) : m_size(n), m_items(nullptr)
{
	if (m_size > 0)
		m_items = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : m_size(other.m_size), m_items(nullptr)
{
	if (m_size > 0)
	{
		m_items = new T[m_size];
		for (unsigned int it = 0; it < m_size; ++it)
			m_items[it] = other.m_items[it];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_items;
}


/* ************************************************************************** */
/* ************************************************************************** */


template <typename T>
Array<T>&	Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		if (m_items != nullptr)
		{
			delete[] m_items;
			m_items = nullptr;
		}

		m_size	= rhs.m_size;
		if (m_size > 0)
		{
			m_items		= new T[rhs.m_size];
			for (unsigned int it = 0; it < m_size; ++it)
				m_items[it] = rhs.m_items[it];
		}
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int idx)
{
	if (idx >= m_size)
		throw ( std::out_of_range("Index out of range") );
	return (m_items[idx]);
}

template <typename T>
const T&	Array<T>::operator[](const unsigned int idx) const
{
	if (idx >= m_size)
		throw ( std::out_of_range("Index out of range") );
	return (m_items[idx]);
}

template <typename T>
unsigned int	Array<T>::size(void)
{
	return ( m_size );
}
