/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:10:03 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/14 12:50:52 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

static void	printHeader(std::string str)
{
	std::cout << BLUE << str << RESET << std::endl;
}

size_t	count(bool do_count)
{
	static size_t count;

	if (do_count)
		++count;
	return (count);
}

size_t	test(std::string descr, bool success)
{
	count(true);

	std::cout	<< LIGHTCYAN << "[" << std::setw(2) << std::setfill('0') << std::right << count(false) << "] " << RESET
				<< std::setw(20) << std::setfill(' ') << std::left << descr << " ";

	if (success)
		std::cout << LIGHTGREEN << "[OK] " << RESET << std::endl;
	else
	{
		std::cout << LIGHTRED << "[KO] " << RESET << std::endl;
		std::cout << LIGHTRED << "     Failed at test: " << count(false) << RESET << std::endl;
		exit (1);
	}

	return (count(false));
}


/* ************************************************************************** */
/* ************************************************************************** */

void	runTests()
{
	size_t	count;

	/* ************************************************************************** */
	printHeader("\nBASIC SWAP TESTS");
	/* ************************************************************************** */
	count = swap_tester<t_color>("ENUM", BLACK, WHITE);
	count = swap_tester<bool>("BOOL", true, false);
	count = swap_tester<char>("CHAR", 'A', 'Z');
	count = swap_tester<int>("INT", 1, 2);
	count = swap_tester<float>("FLOAT", 1.25f, 2.75f);
	count = swap_tester<double>("DOUBLE", 1.25, 2.75);
	count = swap_tester<std::string>("STD::STRING", std::string("Hello"), std::string("World"));
	int*	p1 = new int(45);
	int*	p2 = new int (55);
	count = test("POINTER", test_swap(p1, p2));
	delete(p1);
	delete(p2);

/* ************************************************************************** */
	printHeader("\nMORE ADVANCED TESTS");
/* ************************************************************************** */
	count = swap_tester<int>("same INT", 42, 42);
	int si1 = 42;
	count = test("self swap INT", test_swap(si1, si1));
	count = swap_tester<std::string>("empty std::string", std::string(), std::string());
	int oi1 = 142, oi2 = 242;
	int& ri1 = oi1;
	int& ri2 = oi2;
	count = test("referenced INT", test_swap(ri1, ri2));

/* ************************************************************************** */
	printHeader("\n******************************");
	printHeader("\nBASIC MIN TESTS");
/* ************************************************************************** */
	count = min_tester<t_color>("MIN ENUM", BLACK, WHITE, BLACK);
	count = min_tester<bool>("MIN BOOL", true, false, false);
	count = min_tester<char>("MIN CHAR", 'A', 'Z', 'A');
	count = min_tester<int>("MIN INT", 1, 2, 1);
	count = min_tester<float>("MIN FLOAT", 1.25f, 2.75f, 1.25f);
	count = min_tester<double>("MIN DOUBLE", 1.25, 2.75, 1.25);
	count = min_tester<long long>("MIN LONG LONG", 9223372036854775807LL, -9223372036854775807LL, -9223372036854775807LL);
	count = min_tester<std::string>("MIN STD::STRING", std::string("aaaa"), std::string("bbbb"), std::string("aaaa"));
	p1 = new int(45);
	p2 = new int (55);
	count = min_tester<int*>("MIN POINTER", p1, p2, p1);
	delete(p1);
	delete(p2);

/* ************************************************************************** */
	printHeader("\nADVANCED MIN TESTS");
/* ************************************************************************** */
	count = min_tester<int>("same values INT", 42, 42, 42);
	int i = 123;
	count = test("same variable INT", test_min<int>(i, i, i));
	count = min_tester<float>("MIN FLOAT INFINITY", std::numeric_limits<float>::infinity(), 1.00f, 1.00f);
	count = min_tester<float>("MIN FLOAT INFINITY", std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity());
	count = min_tester<float>("MIN FLOAT NAN", std::numeric_limits<float>::quiet_NaN(), 1.00f, 1.00f);
	count = min_tester<float>("MIN FLOAT -ZERO", -0.0f, 0.00f, -0.00f);
	count = min_tester<float>("MIN FLOAT -ZERO", -0.0f, 0.00f, 0.00f);
	count = min_tester<std::string>("empty STD::STRING", std::string(), std::string(), std::string());
	count = min_tester<std::string>("empty vs non-empty STD::STRING", std::string(), std::string("non-empty"), std::string());

	int a, b;

	a = 40;	b = 42;
	count = cmp_ptr_tester<int>("cmp ptr a < b", min<int>, &a, &b, &a);
	a = 42;	b = 42;
	count = cmp_ptr_tester<int>("cmp ptr a == b", min<int>, &a, &b, &b);

/* ************************************************************************** */
	printHeader("\n******************************");
	printHeader("\nBASIC MAX TESTS");
/* ************************************************************************** */
	count = max_tester<t_color>("MAX ENUM", BLACK, WHITE, WHITE);
	count = max_tester<bool>("MAX BOOL", true, false, true);
	count = max_tester<char>("MAX CHAR", 'A', 'Z', 'Z');
	count = max_tester<int>("MAX INT", 1, 2, 2);
	count = max_tester<float>("MAX FLOAT", 1.25f, 2.75f, 2.75f);
	count = max_tester<double>("MAX DOUBLE", 1.25, 2.75, 2.75);
	count = max_tester<long long>("MAX LONG LONG", 9223372036854775807LL, -9223372036854775807LL, 9223372036854775807LL);
	count = max_tester<std::string>("MAX STD::STRING", std::string("aaaa"), std::string("bbbb"), std::string("bbbb"));
	p1 = new int(45);
	p2 = new int (55);
	count = max_tester<int*>("MAX POINTER", p1, p2, p2);
	delete(p1);
	delete(p2);

/* ************************************************************************** */
	printHeader("\nADVANCED MAX TESTS");
/* ************************************************************************** */
	count = max_tester<int>("same values INT", 42, 42, 42);
	i = 123;
	count = test("same variable INT", test_max<int>(i, i, i));
	count = max_tester<float>("MAX FLOAT INFINITY", std::numeric_limits<float>::infinity(), 1.00f, std::numeric_limits<float>::infinity());
	count = max_tester<float>("MAX FLOAT INFINITY", std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());
	count = max_tester<float>("MAX FLOAT NAN", std::numeric_limits<float>::quiet_NaN(), 1.00f, 1.00f);
	count = max_tester<float>("MAX FLOAT -ZERO", -0.0f, 0.00f, -0.00f);
	count = max_tester<float>("MAX FLOAT -ZERO", -0.0f, 0.00f, 0.00f);
	count = max_tester<std::string>("empty STD::STRING", std::string(), std::string(), std::string());

	a = 52;	b = 42;
	count = cmp_ptr_tester<int>("cmp ptr a > b", max<int>, &a, &b, &a);
	a = 42;	b = 42;
	count = cmp_ptr_tester<int>("cmp ptr a == b", max<int>, &a, &b, &b);

	std::cout << LIGHTGREEN << "\n=> ALL tests passed " << count << "/" << count << " 🥳\n" << RESET << std::endl;	
}