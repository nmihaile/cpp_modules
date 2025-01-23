/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:17 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/23 17:03:35 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include "../BitcoinExchange.hpp"

int	main(void)
{
	BitcoinExchange btcEx;
	btcEx.loadPriceTable();


	print_test_result();

	return (0);
}
