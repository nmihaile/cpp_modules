/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:07:32 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/09 19:24:14 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "VectorPmergeMe.hpp"
#include "ListPmergeMe.hpp"

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
		VectorPmergeMe	vec_me;
		ListPmergeMe	lst_me;
		vec_me.parseArguments(ac, av);
		lst_me.parseArguments(ac, av);

		vec_me.print("   Before", true, false);
		vec_me.sort();
		lst_me.sort();
		vec_me.print("VEC After", true, false);
		lst_me.print("LST After", true, false);
		vec_me.printTime();
		lst_me.printTime();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
