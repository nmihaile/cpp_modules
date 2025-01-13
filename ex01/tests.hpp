/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:10:23 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/13 16:22:26 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TESTS_HPP
#define TESTS_HPP

#include <string>
#include "iter.hpp"
#include "tester.hpp"

#define ARRAY_SIZE 20

void	test_int_timesTwo(int arr_size);
void	test_string_capitalize(int arr_size);
void	test_array_size_zero(int arr_size);
void	test_array_size_one(int arr_size);
void	test_NULL_array(int arr_size);
void	test_array_same_values(int arr_size);

#endif
