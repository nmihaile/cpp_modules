/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:10:34 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/16 10:43:38 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

#include "tester.hpp"
#include "tests.hpp"

int	main(void)
{
	TEST(test_access_of_int_arr_0, Array<int>(0), "Index out of range\n");
	TEST(test_valid_int_array, Array<int>(10), "0 1 2 3 4 5 6 7 8 9 ");
	TEST(test_access_last_item, Array<int>(10), "9");
	TEST(test_negative_index, Array<int>(10), "Index out of range\n");
	TEST(test_int_array_constructor_initialization, Array<int>(10), "0 0 0 0 0 0 0 0 0 0 ");
	TEST(test_deepcopy_on_copy_constructor, Array<int>(10), "0 1 2 3 4 5 6 7 8 9 ");
	TEST(test_int_array_copy_assignemnt_op, Array<int>(10), "0 1 2 3 4 5 6 7 8 9 ");
	
	TEST(test_int_array_size_method, Array<int>(0), "0");
	TEST(test_int_array_size_method, Array<int>(42), "42");
	TEST(test_assignemnt_of_item, Array<int>(11), "42");
	
	TEST(test_float_arr, Array<float>(10), "0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 ");
	TEST(test_str_arr, Array<std::string>(10), "one two three four five six seven eight nine ten ");

	print_test_result("", "");

	return (0);
}
