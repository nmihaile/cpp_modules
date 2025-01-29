/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:03:18 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/29 15:20:54 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

void	exit_with_msg(std::string msg, int exit_code)
{
	std::cout << msg << std::endl;
	exit(exit_code);
}

int	main(int ac, char **av)
{
	if (ac != 2)	
		exit_with_msg("usage: ./RPN \"expression\"", 0);

	RPN	rpn;
	std::cout << rpn.evaluate(av[1]) << std::endl;

	return (0);
}
