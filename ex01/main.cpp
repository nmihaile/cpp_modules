/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:18:59 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/13 18:19:38 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "tester.hpp"
#include "tests.hpp"

int	main(void)
{

	test<int>(test_int_timesTwo     	, 11, std::string("0 2 4 6 8 10 12 14 16 18 20 ") );
	test<int>(test_string_capitalize	,  3, std::string("HALLO WORLD WHERE ARE YOU ") );
	test<int>(test_array_size_zero		,  0, "");
	test<int>(test_array_size_one		,  1, "84 ");
	test<int>(test_NULL_array			, 10, "Array pointer must not be NULL\n");
	test<int>(test_array_same_values	, 10, "10 10 10 10 10 10 10 10 10 10 ");
	test<int>(test_floats				,  7, "0 2.25 9.8596 1e+06 1e+12 inf nan ");
	test<int>(test_custom_type			,  5, "(0.00, 2.00) (0.00, 4.00) (0.00, 8.00) (0.00, 16.00) (0.00, 32.00) ");

	print_test_result("");

	return (0);
}
