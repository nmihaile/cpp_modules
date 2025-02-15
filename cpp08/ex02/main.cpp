/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:55:13 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/22 11:42:26 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include "MutantStack.hpp"
#include "tester.hpp"

template <typename IT>
std::string printSpace(const IT& it, const IT& end)
{
	return ((it != std::prev(end)) ? " " : "");
};

void	test_subject_example_MutantStack_vs_list(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	test_subject_example_list(void)
{
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);

	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	test_basic_MutantStack(void)
{
	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);
	ms.push(6);
	ms.push(42);

	for (MutantStack<int>::iterator it = ms.begin(); it < ms.end(); ++it)
		std::cout << *it << printSpace<MutantStack<int>::iterator>(it, ms.end());
}

void	test_underlying_vector_container(void)
{
	MutantStack<int, std::vector<int>> ms;
	ms.push(42);
	ms.push(43);
	ms.push(44);
	ms.push(45);
	ms.push(46);

	for (MutantStack<int, std::vector<int>>::iterator it = ms.begin(); it < ms.end(); ++it)
		std::cout << *it << printSpace<typename MutantStack<int, std::vector<int>>::iterator>(it, ms.end());
}

void	test_underlying_list_container(void)
{
	MutantStack<int, std::list<int>> ms;
	ms.push(142);
	ms.push(143);
	ms.push(144);
	ms.push(145);
	ms.push(146);

	for (MutantStack<int, std::list<int>>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << printSpace<typename MutantStack<int, std::list<int>>::iterator>(it, ms.end());
}

void	test_MutantStack_push_and_pop_empty(void)
{
	MutantStack<int> ms;
	ms.push(1);		ms.push(2);		ms.push(3);		ms.push(4);		ms.push(5);		ms.push(6);		ms.push(42);
	ms.pop();		ms.pop();		ms.pop();		ms.pop();		ms.pop();		ms.pop();		ms.pop();

	for (MutantStack<int>::iterator it = ms.begin(); it < ms.end(); ++it)
		std::cout << *it << printSpace<MutantStack<int>::iterator>(it, ms.end());
}

void	test_reverse_iterator(void)
{
	MutantStack<int> ms;
	ms.push(1);	ms.push(2);	ms.push(3);	ms.push(4);	ms.push(5);	ms.push(6);

	for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it < ms.rend(); ++it)
		std::cout << *it << printSpace<MutantStack<int>::reverse_iterator>(it, ms.rend());
}

void	test_const_iterator(void)
{
	MutantStack<int> ms;
	ms.push(1);	ms.push(2);	ms.push(3);	ms.push(4);	ms.push(5);	ms.push(6);

	for (MutantStack<int>::const_iterator it = ms.cbegin(); it < ms.cend(); ++it)
		std::cout << *it << printSpace<MutantStack<int>::const_iterator>(it, ms.cend());
}

void	test_const_reverse_iterator(void)
{
	MutantStack<int> ms;
	ms.push(1);	ms.push(2);	ms.push(3);	ms.push(4);	ms.push(5);	ms.push(6);

	for (MutantStack<int>::const_reverse_iterator it = ms.crbegin(); it < ms.crend(); ++it)
		std::cout << *it << printSpace<MutantStack<int>::const_reverse_iterator>(it, ms.crend());
}

void	test_copy_constructor(void)
{
	MutantStack<int> ms;
	ms.push(1);	ms.push(2);	ms.push(3);	ms.push(4);	ms.push(5);	ms.push(6);

	MutantStack<int> copy(ms);

	for (MutantStack<int>::iterator it = copy.begin(); it < copy.end(); ++it)
		std::cout << *it << printSpace<MutantStack<int>::iterator>(it, copy.end());
}

void	test_copy_assignement_operator_overload(void)
{
	MutantStack<int> ms;
	ms.push(1);	ms.push(2);	ms.push(3);	ms.push(4);	ms.push(5);	ms.push(6);

	MutantStack<int> copy;
	copy.push(111);	copy.push(112);	copy.push(113);	copy.push(114);	copy.push(115);	copy.push(116);

	copy = ms;

	for (MutantStack<int>::iterator it = copy.begin(); it < copy.end(); ++it)
		std::cout << *it << printSpace<MutantStack<int>::iterator>(it, copy.end());
}

void	test_empty_MutantStack_iterators(void)
{
	MutantStack<int> ms;
	MutantStack<int>::iterator					it		= ms.begin();
	MutantStack<int>::reverse_iterator			rit		= ms.rbegin();
	MutantStack<int>::reverse_iterator			rite	= ms.rend();
	MutantStack<int>::const_reverse_iterator	crit	= ms.crbegin();
	MutantStack<int>::const_reverse_iterator	crite	= ms.crend();

	if (it == ms.end() &&
		it == rit.base() && it == rite.base() &&
		it == crit.base() && it == crite.base())
		std::cout << "Success: all iterators point to the same place.";
	else
		std::cout << "Error: iterators are different for empty MutantStack";
}

void	test_mixed_push_and_pop(void)
{
	MutantStack<int> ms;
	ms.push(1);	ms.push(2); ms.pop(); ms.push(3); ms.push(4); ms.pop(); ms.push(5);
	ms.push(6); ms.pop(); ms.push(7); ms.push(8); ms.pop(); ms.push(9); ms.push(10); ms.pop();

	for (MutantStack<int>::iterator it = ms.begin(); it < ms.end(); ++it)
		std::cout << *it << printSpace<MutantStack<int>::iterator>(it, ms.end());
}

void	test_persistent_iterator_modification(void)
{
	MutantStack<int> ms;
	ms.push(1);	ms.push(2); ms.push(3); ms.push(4); ms.push(5);
	ms.push(6); ms.push(7); ms.push(8); ms.push(9); ms.push(10);

	for (MutantStack<int>::iterator it = ms.begin(); it < ms.end(); ++it)
		*it *= 10;

	for (MutantStack<int>::iterator it = ms.begin(); it < ms.end(); ++it)
		std::cout << *it << printSpace<MutantStack<int>::iterator>(it, ms.end());
}

void	test_persistent_reverse_iterator_modification(void)
{
	MutantStack<int> ms;
	ms.push(1);	ms.push(2); ms.push(3); ms.push(4); ms.push(5);
	ms.push(6); ms.push(7); ms.push(8); ms.push(9); ms.push(10);

	for (MutantStack<int>::iterator it = ms.begin(); it < ms.end(); ++it)
		*it *= 10;

	for (MutantStack<int>::iterator it = ms.begin(); it < ms.end(); ++it)
		std::cout << *it << printSpace<MutantStack<int>::iterator>(it, ms.end());
}

int	main(void)
{

	TEST(test_subject_example_MutantStack_vs_list, captureStdout(test_subject_example_list));
	TEST(test_basic_MutantStack, "1 2 3 4 5 6 42");
	TEST(test_underlying_vector_container, "42 43 44 45 46");
	TEST(test_underlying_list_container, "142 143 144 145 146");
	TEST(test_MutantStack_push_and_pop_empty, "");
	TEST(test_reverse_iterator, "6 5 4 3 2 1");
	TEST(test_const_iterator, "1 2 3 4 5 6");
	TEST(test_const_reverse_iterator, "6 5 4 3 2 1");
	TEST(test_copy_constructor, "1 2 3 4 5 6");
	TEST(test_copy_assignement_operator_overload, "1 2 3 4 5 6");
	TEST(test_empty_MutantStack_iterators, "Success: all iterators point to the same place.");
	TEST(test_mixed_push_and_pop, "1 3 5 7 9");
	TEST(test_persistent_iterator_modification, "10 20 30 40 50 60 70 80 90 100");
	TEST(test_persistent_reverse_iterator_modification, "10 20 30 40 50 60 70 80 90 100");

	print_test_result();

	return (0);
}
