/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:40:50 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/13 16:50:37 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

template <typename T>
void	print_inline_item(T& item)
{
	std::cout << item << " ";
}

template <typename T>
void	test(void (*test_func)(T input), T input, std::string expected)
{
	std::stringstream	buff;
	std::streambuf*		obuff = std::cout.rdbuf(buff.rdbuf());

	total_count(true);

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
		passed_count(true);
		std::cout << LIGHTGREEN << "[" << total_count(false) << "] ";
		return ;
	}

	print_test_result( buff.str() );
	exit(1);
}
