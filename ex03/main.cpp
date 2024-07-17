/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:12:42 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/17 19:49:28 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "bsp.hpp"

#define LIGHTRED		"\033[0;91m"
#define LIGHTGREEN		"\033[0;92m"
#define LIGHTYELLOW		"\033[0;93m"
#define LIGHTBLUE		"\033[0;94m"
#define LIGHTMAGENTA	"\033[0;95m"
#define LIGHTCYAN		"\033[0;96m"
#define DARKGRAY		"\033[0330;90m"
#define RESET			"\033[0m"

void	check_point(Point a, Point b, Point c, Point point)
{
	if (bsp(a, b, c, point))
		std::cout << LIGHTGREEN << "TA-DA 🎉 - the " << point << " is inside." << RESET << std::endl;
	else
		std::cout << LIGHTRED << "What a bummer 😧 - the " << point << " is outside" << RESET << std::endl;	
}

int	main(void)
{

	Point	a(0.0f, 0.0f);
	Point	b(2.f, 4.f);
	Point	c(4.f, 2.f);

	check_point(a, b, c, Point(2.f, 4.f));
	check_point(a, b, c, Point(2.f, 1.f));
	check_point(a, b, c, Point(.5f, .5f));
	check_point(a, b, c, Point(.75f, .75f));
	check_point(a, b, c, Point(3.f, 3.f));

	return (0);
}