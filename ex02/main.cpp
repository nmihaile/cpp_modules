/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:07:32 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/03 15:10:57 by nmihaile         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	if (ac <= 1)
		printf_exit("\033[92musage: \033[95m./PmergeMe <num1> <num2> ... <numN>\033[0m", 1);

	try
	{
		VectorPmergeMe	pmergeme;
		pmergeme.parseArguments(ac - 1, &av[1]);
		pmergeme.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
