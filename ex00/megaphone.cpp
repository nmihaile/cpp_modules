/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:33:28 by nmihaile          #+#    #+#             */
/*   Updated: 2024/06/29 12:18:24 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	shout(std::string str)
{
	for (std::string::iterator it = str.begin(); it < str.end(); ++it)
		std::cout << (char)std::toupper(*it);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		for (int i = 1; i < ac; i++)
			shout(std::string(av[i]));
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
