/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:54:00 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/16 10:38:56 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Array.hpp"

void	test_access_of_int_arr_0(Array<int> arr);
void	test_valid_int_array(Array<int> arr);
void	test_access_last_item(Array<int> arr);
void	test_negative_index(Array<int> arr);
void	test_int_array_constructor_initialization(Array<int> arr);
void	test_deepcopy_on_copy_constructor(Array<int> arr);
void	test_int_array_copy_assignemnt_op(Array<int> arr);
void	test_int_array_size_method(Array<int> arr);
void	test_assignemnt_of_item(Array<int> arr);
void	test_float_arr(Array<float> arr);
void	test_str_arr(Array<std::string> arr);

#endif
