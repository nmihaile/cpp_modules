/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:44:58 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/15 17:28:48 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

size_t	test_count(bool do_count)
{
	static size_t	count;
	if (do_count)
		++count;
	return (count);
}

size_t	test_passed(bool do_count)
{
	static size_t	count;
	if (do_count)
		++count;
	return (count);
}

void	print_test_result(std::string msg, std::string expected)
{
	if (test_passed(false) == test_count(false))
	{
		std::cout << std::endl;
		std::cout << "  🎉🥳 All " << std::setw(2) << test_count(false) <<" tests passed! 🥳🎉" << std::endl;
		std::cout << LIGHTGREEN << "══════════════════════════════════" << RESET << std::endl;
	}
	else
	{
		std::cout << LIGHTRED << "[KO]\n" << RESET << std::endl;
		std::cout << LIGHTCYAN		<< "output  : [" <<  RESET << msg << LIGHTCYAN << "]" << RESET << std::endl;
		if (!expected.empty())
			std::cout << LIGHTCYAN	<< "expected: [" <<  RESET << expected << LIGHTCYAN << "]" << RESET << std::endl;

		std::cout << "  ❌ " << LIGHTRED << "Failed at test: " << LIGHTCYAN << "[" << test_count(false) << "]" << std::endl;
		std::cout << RESET << "     please investigate and debug accordingly…" << std::endl;
		std::cout << LIGHTRED << "══════════════════════════════════════════════════" << RESET << std::endl;

		exit(1);
	}
}
