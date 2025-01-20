/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:22:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/20 11:12:19 by nmihaile         ###   ########.fr       */
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
	static std::uniform_int_distribution<>	dist(0, 999999);

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

int	main(void)
{

	TEST(test_exmple_from_subject, "2\n14\n");
	TEST(test_addRange, "6\n997740\n");
	TEST(test_range_constructor, "1\n998984\n");

	// test_addRange();

	print_test_result();
	
	return (0);
}
