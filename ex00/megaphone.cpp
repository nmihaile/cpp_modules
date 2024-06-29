/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:33:28 by nmihaile          #+#    #+#             */
/*   Updated: 2024/06/29 11:33:33 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	shout(char *str)
{
	for (int i = 0; str[i]; i++)
		std::cout << (char)std::toupper(str[i]);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		for (int i = 1; i < ac; i++)
			shout(av[i]);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
