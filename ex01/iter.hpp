/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:31:15 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/13 17:04:50 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <stdexcept>

template <typename T, typename Fn>
void	iter(T* arr, size_t size, Fn func)
{
	if (arr == nullptr)
		throw ( std::invalid_argument("Array pointer must not be NULL") );
	for (size_t idx = 0; idx < size; ++idx)
		func(arr[idx]);
}

#endif
