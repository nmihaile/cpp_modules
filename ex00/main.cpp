/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:25:37 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/20 15:01:35 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::convert(av[1]);

	// Literall Types
	// singel character

	// num chars -> aka int
	// 123.123f / -inff / inff
	// -> float
	// 234.234 -> double
	//  -inf  inf
	//

	return (0);
}
