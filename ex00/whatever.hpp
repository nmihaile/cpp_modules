/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:24:14 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/14 12:39:17 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void	swap(T& a, T&b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T&	min(T& a, T&b)
{
	return ( a < b ? a : b );
}

template<typename T>
T&	max(T& a, T&b)
{
	return ( a > b ? a : b );
}

#endif