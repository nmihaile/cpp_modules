/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:55:13 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/21 18:52:05 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"
#include "tester.hpp"

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

int	main(void)
{

	TEST(test_subject_example_MutantStack_vs_list, captureStdout(test_subject_example_list));

	print_test_result();

	return (0);
}
