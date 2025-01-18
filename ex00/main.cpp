/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:41:12 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/18 12:17:43 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"
#include "tester.hpp"

void	test_valid_vector_find(void)
{
	std::vector<int>			arr = { 40, 41, 42, 43, 44 };
	std::vector<int>::iterator	it = easyfind<std::vector<int>>(arr, 42);
	std::cout << *it;
}

void	test_invalid_vector_find(void)
{
	std::vector<int>			arr = { 30, 31, 32, 33, 34 };
	std::vector<int>::iterator	it = easyfind<std::vector<int>>(arr, 42);
	std::cout << *it;
}

void	test_empty_vector(void)
{
	std::vector<int>			arr;
	std::vector<int>::iterator	it = easyfind<std::vector<int>>(arr, 42);
	std::cout << *it;
}

void	test_huge_vector(void)
{
	std::vector<int>			arr;
	arr.reserve(2000000);
	for (size_t it = 0; it < 20000000; ++it)
		arr.emplace_back(it);
	std::vector<int>::iterator	first = easyfind<std::vector<int>>(arr, 0);
	std::vector<int>::iterator	last = easyfind<std::vector<int>>(arr, 19999999);
	std::cout << *first << " " << *last;
}

int	main(void)
{

	TEST(test_valid_vector_find, "42");
	TEST(test_invalid_vector_find, "element not found\n");
	TEST(test_empty_vector, "element not found\n");
	TEST(test_huge_vector, "0 19999999");

	// std::vector<int>	v, w;

	// v.emplace_back(40);
	// v.emplace_back(41);
	// v.emplace_back(42);
	// v.emplace_back(43);
	// v.emplace_back(44);
	// v.emplace_back(0);
	// v.emplace_back(45);

	// try
	// {
	// 	// int si = 50;
	// 	// std::vector<int>::iterator	it = easyfind<std::vector<int>>(v, 50);
	// 	// std::cout << "found " << *it << std::endl;
	// 	std::vector<int>::iterator	it = easyfind<std::vector<int>>(v, 42);
	// 	std::cout << "found " << *it << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	

	return (0);
}
