/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:55:13 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/21 19:12:29 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <iterator>
#include "MutantStack.hpp"
#include "tester.hpp"

template <typename IT>
std::string printSpace(const IT& it, const IT& end)
{
	return ((it != end - 1) ? " " : "");
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

int	main(void)
{

	TEST(test_subject_example_MutantStack_vs_list, captureStdout(test_subject_example_list));
	TEST(test_basic_MutantStack, "1 2 3 4 5 6 42");

	print_test_result();

	return (0);
}
