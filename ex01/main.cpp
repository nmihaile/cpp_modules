/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:22:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/20 12:32:23 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <random>
#include "Span.hpp"
#include "tester.hpp"

int	rnd()
{
	static std::random_device				rd;
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

	print_test_result();
	
	return (0);
}
