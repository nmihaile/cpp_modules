/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:30:17 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/11 10:47:32 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include "ft_replace.hpp"

static void check_valid_arguments(int ac)
{
	if (ac != 4)
	{
		std::cout	<< "ftrplc: Wrong number of arguemnts\n"
					<< "usage: ./ftrplc <filename> <string1> <string2>" << std::endl;
		exit(1);
	}
}

int	main(int ac, char **av)
{
	check_valid_arguments(ac);
	if (ft_replace(av[1], av[2], av[3]))
		return (1);
	return (0);
}
