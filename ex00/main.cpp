/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:49:15 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/23 12:36:01 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_with_msg("usage: ./btc <input.txt>");

	BitcoinExchange	btcEx;

	(void)av;

	return (0);
}
