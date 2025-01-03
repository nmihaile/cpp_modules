/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:25:37 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/03 19:10:52 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::convert(av[1]);

	// std::cout << "-----------" << std::endl;
	// ScalarConverter::convert("             1.0f");



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
