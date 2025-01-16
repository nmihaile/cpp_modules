/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:53:59 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/16 09:27:31 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_access_of_int_arr_0(Array<int> arr)
{
	arr[0] = 42;
}

void	test_valid_int_array(Array<int> arr)
{
	for (unsigned int it = 0; it < arr.size(); ++it)
		arr[it] = static_cast<int>(it);
		
	for (unsigned int it = 0; it < arr.size(); ++it)
		std::cout << arr[it] << " ";
}

void	test_int_array_constructor_initialization(Array<int> arr)
{
	for (unsigned int it = 0; it < arr.size(); ++it)
		std::cout << arr[it] << " ";
}

void	test_int_array_copy_assignemnt_op(Array<int> arr)
{
	Array<int>	assigned_arr;

	// assign values to the orig array
	for (unsigned int it = 0; it < arr.size(); ++it)
		arr[it] = static_cast<int>(it);

	// call copy assignemnt operator
	assigned_arr = arr;

	// print out the copied  array
	for (unsigned int it = 0; it < arr.size(); ++it)
		std::cout << assigned_arr[it] << " ";
}

void	test_int_array_size_method(Array<int> arr)
{
	std::cout << arr.size();
}

void	test_assignemnt_of_item(Array<int> arr)
{
	arr[arr.size() / 2] = 42;
	std::cout << arr[arr.size() / 2];
}
