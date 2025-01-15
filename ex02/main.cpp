/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:10:34 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/15 16:57:44 by nmihaile         ###   ########.fr       */
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


	Array<int>			arr(10);
	// std::cout << arr.m_items[0] << std::endl;

	int& i = arr[5];
	i = 25;

	for (unsigned int it = 0; it < arr.size(); ++it)
		std::cout << arr[it] << std::endl;


	return (0);
}
