/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:49:15 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/28 17:46:35 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "BitcoinExchange.hpp"

void	exit_with_msg(std::string msg, int exit_code)
{
	std::cout << msg << std::endl;
	exit(exit_code);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_with_msg("usage: ./btc <input.txt>", 0);

	try
	{
		BitcoinExchange	btcEx;
		btcEx.loadPriceTable("data.csv");
		btcEx.evaluateInputFile(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[91m" << e.what() << "\033[0m" << '\n';
		exit(1);
	}	

	return (0);
}
