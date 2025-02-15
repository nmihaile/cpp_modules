/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:28:07 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/11 22:15:07 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "usage: ./harlFilter <DEBUG|INFO|WARNING|ERROR>" << std::endl;
		return (1);
	}
		
	Harl Hal;
	Hal.set_filter(av[1]);
	Hal.complain();

	return (0);
}

