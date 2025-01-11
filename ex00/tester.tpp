/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:01:51 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/11 20:24:42 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

template <typename T>
bool	test_swap(T& a, T& b)
{
	T orig_a = a;
	T orig_b = b;
	swap(a, b);
	return ( a == orig_b && b == orig_a );
}

template <typename T>
bool	test_min(T a, T b, T expected_min)
{
	T min_v = min(a, b);
	return ( min_v == expected_min );
}

template <typename T>
bool	test_max(T a, T b, T expected_max)
{
	T max_v = max(a, b);
	return ( max_v == expected_max );
}


/* ************************************************************************** */
/* Testers																	  */
/* ************************************************************************** */


template <typename T>
size_t	swap_tester(std::string descr, T a, T b)
{
	return test(descr, test_swap(a, b));
}

template <typename T>
size_t	min_tester(std::string descr, T a, T b, T expected_min)
{
	return test(descr, test_min(a, b, expected_min));
}

template <typename T>
size_t	max_tester(std::string descr, T a, T b, T expected_max)
{
	return test(descr, test_max(a, b, expected_max));
}
