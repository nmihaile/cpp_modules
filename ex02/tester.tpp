/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:49:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/15 17:27:48 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

template <typename T>
void	test(void (*test_func)(T input), T input, std::string expected)
{
	test_count(true);

	std::cout << LIGHTCYAN << "[" << std::setw(2) << std::setfill('0') << test_count(false) << "]" << RESET << " -> ";

	std::stringstream	buff;
	std::streambuf*		obuff = std::cout.rdbuf( buff.rdbuf() );

	try
	{
		test_func(input);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	std::cout.rdbuf(obuff);
	if (buff.str() == expected)
	{
		test_passed(true);
		std::cout << LIGHTGREEN << "[OK] " << RESET << std::endl;
		return ;
	}

	print_test_result(buff.str(), expected);
	exit(1);
}