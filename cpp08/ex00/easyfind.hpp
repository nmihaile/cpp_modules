/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:24:54 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/18 11:47:51 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename  T::iterator	easyfind(T& type, const int& i)
{
	typename T::iterator it = std::find(type.begin(), type.end(), i);
	if (it == type.end())
		throw ( std::runtime_error("element not found") );
	return (it);
};

template <typename T>
typename  T::const_iterator	easyfind(const T& type, const int& i)
{
	typename T::const_iterator it = std::find(type.begin(), type.end(), i);
	if (it == type.end())
		throw ( std::runtime_error("element not found") );
	return (it);
};

#endif
