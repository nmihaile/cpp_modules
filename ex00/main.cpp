/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:49:15 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/25 17:26:05 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "BitcoinExchange.hpp"

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
		std::cerr << "\033[91m" << e.what() << "\033[0m" << '\n';
		exit(1);
	}	

	return (0);
}
