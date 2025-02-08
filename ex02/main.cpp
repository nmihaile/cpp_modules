/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:07:32 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/08 16:33:11 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "VectorPmergeMe.hpp"

void	printf_exit(std::string msg, int exit_code)
{
	std::cout << msg << std::endl;
	exit(exit_code);
}

// void	print_seq(std::vector<Item> seq, unsigned int count)
// {
// 	std::cout	<< "\033[93m[" << std::setw(2) << count << "] \033[94m";
// 	for (auto& s : seq)
// 		std::cout << s.value << " ";
// 	std::cout << "\033[0m\n";
// }

int	main(int ac, char **av)
{
	if (ac <= 1)
		printf_exit("\033[92musage: \033[95m./PmergeMe <num1> <num2> ... <numN>\033[0m", 1);

	try
	{
		VectorPmergeMe	vec_pmergeme;
		vec_pmergeme.parseArguments(ac, av);

		// print_seq(vec_pmergeme.insertOrder(1), 1);
		// print_seq(vec_pmergeme.insertOrder(2), 2);
		// print_seq(vec_pmergeme.insertOrder(3), 3);
		// print_seq(vec_pmergeme.insertOrder(4), 4);
		// print_seq(vec_pmergeme.insertOrder(5), 5);
		// print_seq(vec_pmergeme.insertOrder(6), 6);
		// print_seq(vec_pmergeme.insertOrder(7), 7);
		// print_seq(vec_pmergeme.insertOrder(8), 8);
		// print_seq(vec_pmergeme.insertOrder(9), 9);
		// print_seq(vec_pmergeme.insertOrder(10), 10);
		// print_seq(vec_pmergeme.insertOrder(11), 11);
		// print_seq(vec_pmergeme.insertOrder(12), 12);
		// print_seq(vec_pmergeme.insertOrder(13), 13);

		vec_pmergeme.print("Before", true, false);
		vec_pmergeme.sort();
		vec_pmergeme.print("After", true, true);
		vec_pmergeme.printTime();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
