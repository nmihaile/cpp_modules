/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:17 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/23 17:08:17 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include "../BitcoinExchange.hpp"

void	test_instantiating_btcEx(void)
{
	BitcoinExchange btcEx;
	btcEx.loadPriceTable();
}

int	main(void)
{

	TEST(test_instantiating_btcEx, "");

	print_test_result();

	return (0);
}
