/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:41:12 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/18 13:08:32 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <array>
#include "easyfind.hpp"
#include "tester.hpp"

void	printDivider(void)
{
	std::cout << BLUE << "----------------------------------------------------------" << RESET << std::endl;
}

/* ************************************************************************** */
/* ************************************************************************** */

void	test_find_existing_element_in_vector(void)
{
	std::vector<int>			arr = { 40, 41, 42, 43, 44 };
	std::vector<int>::iterator	it = easyfind<std::vector<int>>(arr, 42);
	std::cout << *it;
}

void	test_find_first_element_in_vector(void)
{
	std::vector<int>			arr = { 40, 41, 42, 43, 44 };
	std::vector<int>::iterator	it = easyfind<std::vector<int>>(arr, 40);
	std::cout << *it;
}

void	test_find_last_element_in_vector(void)
{
	std::vector<int>			arr = { 40, 41, 42, 43, 44 };
	std::vector<int>::iterator	it = easyfind<std::vector<int>>(arr, 44);
	std::cout << *it;
}

void	test_find_nonexistent_element_in_vector(void)
{
	std::vector<int>			arr = { 30, 31, 32, 33, 34 };
	std::vector<int>::iterator	it = easyfind<std::vector<int>>(arr, 42);
	std::cout << *it;
}

void	test_find_in_empty_vector(void)
{
	std::vector<int>			arr;
	std::vector<int>::iterator	it = easyfind<std::vector<int>>(arr, 42);
	std::cout << *it;
}

void	test_find_in_huge_vector(void)
{
	std::vector<int>			arr;
	arr.reserve(2000000);
	for (size_t it = 0; it < 20000000; ++it)
		arr.emplace_back(it);
	std::vector<int>::iterator	first = easyfind<std::vector<int>>(arr, 0);
	std::vector<int>::iterator	last = easyfind<std::vector<int>>(arr, 19999999);
	std::cout << *first << " " << *last;
}


/* ************************************************************************** */
/* ************************************************************************** */


void	test_find_existing_element_in_list(void)
{
	std::list<int>				arr = { 40, 41, 42, 43, 44 };
	std::list<int>::iterator	it = easyfind<std::list<int>>(arr, 42);
	std::cout << *it;
}

void	test_find_first_element_in_list(void)
{
	std::list<int>				arr = { 40, 41, 42, 43, 44 };
	std::list<int>::iterator	it = easyfind<std::list<int>>(arr, 40);
	std::cout << *it;
}

void	test_find_last_element_in_list(void)
{
	std::list<int>				arr = { 40, 41, 42, 43, 44 };
	std::list<int>::iterator	it = easyfind<std::list<int>>(arr, 44);
	std::cout << *it;
}

void	test_find_nonexisting_element_in_list(void)
{
	std::list<int>				arr = { 30, 31, 32, 33, 34 };
	std::list<int>::iterator	it = easyfind<std::list<int>>(arr, 42);
	std::cout << *it;
}

void	test_find_in_empty_list(void)
{
	std::list<int>			arr;
	std::list<int>::iterator	it = easyfind<std::list<int>>(arr, 42);
	std::cout << *it;
}

void	test_find_in_huge_list(void)
{
	std::list<int>			arr;
	for (size_t it = 0; it < 2000000; ++it)
		arr.push_back(it);
	std::list<int>::iterator	first = easyfind<std::list<int>>(arr, 0);
	std::list<int>::iterator	last = easyfind<std::list<int>>(arr, 1999999);
	std::cout << *first << " " << *last;
}


/* ************************************************************************** */
/* ************************************************************************** */


void	test_find_existing_element_in_array(void)
{
	std::array<int, 5>				arr = { 40, 41, 42, 43, 44 };
	std::array<int, 5>::iterator	it = easyfind<std::array<int, 5>>(arr, 42);
	std::cout << *it;
}

void	test_find_first_element_in_array(void)
{
	std::array<int, 5>				arr = { 40, 41, 42, 43, 44 };
	std::array<int, 5>::iterator	it = easyfind<std::array<int, 5>>(arr, 40);
	std::cout << *it;
}

void	test_find_last_element_in_array(void)
{
	std::array<int, 5>				arr = { 40, 41, 42, 43, 44 };
	std::array<int, 5>::iterator	it = easyfind<std::array<int, 5>>(arr, 44);
	std::cout << *it;
}

void	test_find_nonexisting_element_in_array(void)
{
	std::array<int, 5>				arr = { 30, 31, 32, 33, 34 };
	std::array<int, 5>::iterator	it = easyfind<std::array<int, 5>>(arr, 42);
	std::cout << *it;
}

void	test_find_in_empty_array(void)
{
	std::array<int, 0>			arr;
	std::array<int, 0>::iterator	it = easyfind<std::array<int, 0>>(arr, 42);
	std::cout << *it;
}

void	test_find_in_huge_array(void)
{
	std::array<int, 2000000>			arr;
	for (size_t it = 0; it < 2000000; ++it)
		arr[it] = it;
	std::array<int, 2000000>::iterator	first = easyfind<std::array<int, 2000000>>(arr, 0);
	std::array<int, 2000000>::iterator	last = easyfind<std::array<int, 2000000>>(arr, 1999999);
	std::cout << *first << " " << *last;
}


int	main(void)
{

	TEST(test_find_existing_element_in_vector, "42");
	TEST(test_find_first_element_in_vector, "40");
	TEST(test_find_last_element_in_vector, "44");
	TEST(test_find_nonexistent_element_in_vector, "element not found\n");
	TEST(test_find_in_empty_vector, "element not found\n");
	TEST(test_find_in_huge_vector, "0 19999999");

	printDivider();

	TEST(test_find_existing_element_in_list, "42");
	TEST(test_find_first_element_in_list, "40");
	TEST(test_find_last_element_in_list, "44");
	TEST(test_find_nonexisting_element_in_list, "element not found\n");
	TEST(test_find_in_empty_list, "element not found\n");
	TEST(test_find_in_huge_list, "0 1999999");

	printDivider();

	TEST(test_find_existing_element_in_array, "42");
	TEST(test_find_first_element_in_array, "40");
	TEST(test_find_last_element_in_array, "44");
	TEST(test_find_nonexisting_element_in_array, "element not found\n");
	TEST(test_find_in_empty_array, "element not found\n");
	TEST(test_find_in_huge_array, "0 1999999");

	return (0);
}
