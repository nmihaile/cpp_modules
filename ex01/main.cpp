/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:22:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/20 19:46:11 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <random>
#include <limits>
#include "Span.hpp"
#include "tester.hpp"

int	rnd()
{
	static std::mt19937						gen(1234567890);
	static std::uniform_int_distribution<>	dist(0, 1234567890);

	return (dist(gen));
}

void	test_exmple_from_subject(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_addRange(void)
{
	Span				sp(1000);
	std::vector<int>	vec;
	vec.reserve(1000);

	for (int i = 0; i < 1000; ++i)
		vec.emplace_back( rnd() );
	
	sp.addRange(vec.begin(), vec.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_range_constructor(void)
{
	std::vector<int>	vec;
	vec.reserve(1000);

	for (int i = 0; i < 1000; ++i)
		vec.emplace_back( rnd() );
	
	Span	sp(vec.begin(), vec.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_zero_capacity_span(void)
{
	Span sp(0);
	sp.addNumber(5);
}

void	test_zero_capacity_span_shortestSpan(void)
{
	Span sp(0);
	std::cout << sp.shortestSpan() << std::endl;
}

void	test_zero_capacity_span_longestSpan(void)
{
	Span sp(0);
	std::cout << sp.longestSpan() << std::endl;
}

void	test_one_capacity_span(void)
{
	Span sp(1);
	sp.addNumber(5);
	sp.addNumber(15);
}

void	test_one_capacity_span_shortestSpan(void)
{
	Span sp(1);
	sp.addNumber(5);
	std::cout << sp.shortestSpan() << std::endl;
}

void	test_one_capacity_span_longestSpan(void)
{
	Span sp(1);
	sp.addNumber(5);
	std::cout << sp.longestSpan() << std::endl;
}

void	test_huge_range_10000(void)
{
	Span				sp(10000);
	std::vector<int>	vec;
	vec.reserve(10000);

	for (int i = 0; i < 10000; ++i)
		vec.emplace_back( rnd() );
	sp.addRange(vec.begin(), vec.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_very_huge_range_1000000(void)
{
	Span				sp(1000000);
	std::vector<int>	vec;
	vec.reserve(1000000);

	for (int i = 0; i < 1000000; ++i)
		vec.emplace_back( rnd() );
	sp.addRange(vec.begin(), vec.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_same_values_in_span(void)
{
	Span				sp(100);
	std::vector<int>	vec;
	vec.reserve(100);

	for (int i = 0; i < 100; ++i)
		vec.emplace_back( 42 );
	sp.addRange(vec.begin(), vec.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_same_values_for_shortes_and_longest(void)
{
	Span				sp(2);

	sp.addNumber(1);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

/* ************************************************************************** */
/* ************************************************************************** */

void	test_addRange_from_array(void)
{
	Span					sp(100);
	std::array<int, 100>	arr;

	for (int i = 0; i < 100; ++i)
		arr[i] = i * i;
	
	sp.addRange(arr.begin(), arr.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_addRange_from_deque(void)
{
	Span			sp(100);
	std::deque<int>	dq;

	for (int i = 0; i < 100; ++i)
		if ( i % 2 == 0)
			dq.emplace_front(i * i);
		else
			dq.emplace_back(i * i);
	
	sp.addRange(dq.begin(), dq.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_addRange_from_list(void)
{
	Span			sp(100);
	std::list<int>	lst;

	for (int i = 0; i < 100; ++i)
		if ( i % 2 == 0)
			lst.push_front(i * i);
		else
			lst.push_back(i * i);
	
	sp.addRange(lst.begin(), lst.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_partial_filled_span_add_valid_range()
{
	Span 				sp(100);
	std::vector<int>	vec;
	for (int i = 0; i < 50; ++i)
	{
		sp.addNumber( rnd() );
		vec.emplace_back( rnd() );
	}
	sp.addRange(vec.begin(), vec.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_partial_filled_span_add_invalid_range()
{
	Span 				sp(100);
	std::vector<int>	vec;
	for (int i = 0; i < 51; ++i)
	{
		sp.addNumber( rnd() );
		vec.emplace_back( rnd() );
	}
	sp.addRange(vec.begin(), vec.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_add_empty_range(void)
{
	Span				sp(50);
	std::vector<int>	vec;
	
	sp.addRange(vec.begin(), vec.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_construct_span_from_empty_range(void)
{
	std::vector<int>	vec;
	
	Span				sp(vec.begin(), vec.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_shortestSpan_more_than_max_int(void)
{	
	Span	sp(3);
	sp.addNumber(-10);
	sp.addNumber(std::numeric_limits<int>::max());

	std::cout << sp.shortestSpan() << std::endl;
}

void	test_shortestSpan_min_int_to_max_int(void)
{	
	Span	sp(3);
	sp.addNumber(std::numeric_limits<int>::min());
	sp.addNumber(std::numeric_limits<int>::max());

	std::cout << sp.shortestSpan() << std::endl;
}

void	test_sparse_range(void)
{	
	Span	sp(3);
	sp.addNumber(std::numeric_limits<int>::min());
	sp.addNumber(0);
	sp.addNumber(std::numeric_limits<int>::max());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int	main(void)
{

	TEST(test_exmple_from_subject, "2\n14\n");
	TEST(test_addRange, "661\n1233303372\n");
	TEST(test_range_constructor, "2625\n1231769575\n");
	TEST(test_zero_capacity_span, "Span has reached its capacity, cannot add more elements.\n");
	TEST(test_zero_capacity_span_shortestSpan, "Not enough elements to calculate a span.\n");
	TEST(test_zero_capacity_span_longestSpan, "Not enough elements to calculate a span.\n");
	TEST(test_one_capacity_span, "Span has reached its capacity, cannot add more elements.\n");
	TEST(test_one_capacity_span_shortestSpan, "Not enough elements to calculate a span.\n");
	TEST(test_one_capacity_span_longestSpan, "Not enough elements to calculate a span.\n");
	TEST(test_huge_range_10000, "13\n1234324388\n");
	TEST(test_very_huge_range_1000000, "0\n1234567196\n");
	TEST(test_same_values_in_span, "0\n0\n");
	TEST(test_same_values_for_shortes_and_longest, "10\n10\n");

	TEST(test_addRange_from_array, "1\n9801\n");
	TEST(test_addRange_from_deque, "1\n9801\n");
	TEST(test_addRange_from_list, "1\n9801\n");
	TEST(test_partial_filled_span_add_valid_range, "163363\n1202164588\n");
	TEST(test_partial_filled_span_add_invalid_range, "Adding this range exceeds Span capacity.\n");

	TEST(test_add_empty_range, "Attempted to use an empty range with the Span.\n");
	TEST(test_construct_span_from_empty_range, "Attempted to use an empty range with the Span.\n");
	TEST(test_shortestSpan_more_than_max_int, "2147483657\n");
	TEST(test_shortestSpan_min_int_to_max_int, "4294967295\n");
	TEST(test_sparse_range, "2147483647\n4294967295\n");

	print_test_result();
	
	return (0);
}
