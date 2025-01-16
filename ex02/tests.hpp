/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:54:00 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/16 09:36:43 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include "Array.hpp"

void	test_access_of_int_arr_0(Array<int> arr);
void	test_valid_int_array(Array<int> arr);
void	test_int_array_constructor_initialization(Array<int> arr);
void	test_int_array_copy_assignemnt_op(Array<int> arr);
void	test_int_array_size_method(Array<int> arr);
void	test_assignemnt_of_item(Array<int> arr);

#endif
