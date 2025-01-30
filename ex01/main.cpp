/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:03:18 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/30 17:45:18 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

void	exit_with_msg(const std::string msg, const int exit_code)
{
	std::cout << msg << std::endl;
	exit(exit_code);
}

int	main(int ac, char **av)
{
	if (ac != 2)	
		exit_with_msg("usage: ./RPN \"expression\"", 0);

	try
	{
		RPN	rpn;
		std::cout << rpn.evaluate(av[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
