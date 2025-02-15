/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:31:37 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/21 15:40:54 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, class MutantContainer>
MutantStack<T, MutantContainer>::MutantStack()
{
}

template <typename T, class MutantContainer>
MutantStack<T, MutantContainer>::MutantStack(const MutantStack& other)
	:	std::stack<T, MutantContainer>(other)
{
}

template <typename T, class MutantContainer>
MutantStack<T, MutantContainer>::~MutantStack()
{
}

template <typename T, class MutantContainer>
MutantStack<T, MutantContainer>&	MutantStack<T, MutantContainer>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return (*this);
}

template <typename T, class MutantContainer>
typename MutantStack<T, MutantContainer>::iterator MutantStack<T, MutantContainer>::begin()
{
	return ( this->c.begin() );
}

template <typename T, class MutantContainer>
typename MutantStack<T, MutantContainer>::iterator MutantStack<T, MutantContainer>::end()
{
	return ( this->c.end() );
}

template <typename T, class MutantContainer>
typename MutantStack<T, MutantContainer>::reverse_iterator MutantStack<T, MutantContainer>::rbegin()
{
	return ( this->c.rbegin() );
}

template <typename T, class MutantContainer>
typename MutantStack<T, MutantContainer>::reverse_iterator MutantStack<T, MutantContainer>::rend()
{
	return ( this->c.rend() );
}

/* ************************************************************************** */

template <typename T, class MutantContainer>
typename MutantStack<T, MutantContainer>::const_iterator MutantStack<T, MutantContainer>::cbegin()
{
	return ( this->c.cbegin() );
}

template <typename T, class MutantContainer>
typename MutantStack<T, MutantContainer>::const_iterator MutantStack<T, MutantContainer>::cend()
{
	return ( this->c.cend() );
}

template <typename T, class MutantContainer>
typename MutantStack<T, MutantContainer>::const_reverse_iterator MutantStack<T, MutantContainer>::crbegin()
{
	return ( this->c.crbegin() );
}

template <typename T, class MutantContainer>
typename MutantStack<T, MutantContainer>::const_reverse_iterator MutantStack<T, MutantContainer>::crend()
{
	return ( this->c.crend() );
}
