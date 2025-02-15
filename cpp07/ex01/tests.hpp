/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:10:23 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/16 11:03:17 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TESTS_HPP
#define TESTS_HPP

#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <limits>
#include "iter.hpp"
#include "tester.hpp"

#define ARRAY_SIZE 20

typedef struct s_vec2
{
	float	x;
	float	y;
}			vec2;

void	test_int_timesTwo(int arr_size);
void	test_string_capitalize(int arr_size);
void	test_array_size_zero(int arr_size);
void	test_array_size_one(int arr_size);
void	test_NULL_array(int arr_size);
void	test_array_same_values(int arr_size);
void	test_floats(int arr_size);
void	test_custom_type(int arr_size);

std::ostream& operator<<(std::ostream& os, const vec2& v);

#endif
