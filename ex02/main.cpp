/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:10:34 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/15 20:51:33 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

#include "tester.hpp"
#include "tests.hpp"

int	main(void)
{
	// Array<int*>			ai(10);
	// Array<int>			arr(15);
	// Array<std::string>	arr_str(25);

	// for (unsigned int it = 0; it < arr_str.size(); ++it)
	// 	arr_str[it] = "hello 42";

	// for (unsigned int it = 0; it < arr_str.size(); ++it)
	// 	std::cout << arr_str[it] << std::endl;

	TEST(test_access_of_int_arr_0, Array<int>(0), "Index out of range\n");
	TEST(test_valid_int_array, Array<int>(10), "0 1 2 3 4 5 6 7 8 9 ");
	TEST(test_int_array_constructor_initialization, Array<int>(10), "0 0 0 0 0 0 0 0 0 0 ");
	TEST(test_int_array_copy_assignemnt_op, Array<int>(10), "0 1 2 3 4 5 6 7 8 9 ");
	
	TEST(test_int_array_size_method, Array<int>(0), "0");
	TEST(test_int_array_size_method, Array<int>(42), "42");
	TEST(test_assignemnt_of_item, Array<int>(11), "42");

	print_test_result("", "");

	Array<int>			arr(10);
	// std::cout << arr.m_items[0] << std::endl;

	int& i = arr[5];
	i = 25;

	for (unsigned int it = 0; it < arr.size(); ++it)
		std::cout << arr[it] << std::endl;


	return (0);
}
