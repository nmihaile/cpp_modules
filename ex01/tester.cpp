/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:37:43 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/13 17:04:21 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

size_t	total_count(bool do_count)
{
	static size_t	count;
	if (do_count)
		++count;
	return (count);
}

size_t	passed_count(bool do_count)
{
	static size_t	count;
	if (do_count)
		++count;
	return (count);
}

void	print_test_result(std::string msg)
{
	if (passed_count(false) == total_count(false))
	{
		std::cout << "\n" << std::endl;
		std::cout << "  🎉🥳 All " << std::setw(2) << total_count(false) <<" tests passed! 🥳🎉" << std::endl;
		std::cout << LIGHTGREEN << "══════════════════════════════════" << RESET << std::endl;
	}
	else
	{
		std::cout << LIGHTRED << "[KO]\n" << RESET << std::endl;
		std::cout << LIGHTCYAN << "out: [" <<  RESET << msg << LIGHTCYAN << "]" << RESET << std::endl;

		std::cout << "  ❌ " << LIGHTRED << "Failed at test: " << LIGHTCYAN << "[" << total_count(false) << "]" << std::endl;
		std::cout << RESET << "     please investigate and debug accordingly…" << std::endl;
		std::cout << LIGHTRED << "══════════════════════════════════════════════════" << RESET << std::endl;

		exit(1);
	}


}
