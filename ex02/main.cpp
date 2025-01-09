/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:17:57 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/09 11:08:59 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "Base.hpp"
#include "ABC.hpp"
#include "utils.hpp"

#define BOLD			"\033[1m"
#define BLUE			"\033[34m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

// RainbowColorCount:
#define RCC 6

static const char *rainbow_colors[RCC] = {
	"\033[91m",
	"\033[93m",
	"\033[92m",
	"\033[96m",
	"\033[94m",
	"\033[95m"
};

typedef struct s_count
{
	size_t	a;
	size_t	b;
	size_t	c;
}	Count;

void	rainbow_print(std::string str)
{
	static size_t	col;
	std::cout << BOLD;
	for(std::string::iterator it = str.begin(); it < str.end(); ++it)
	{
		std::cout << rainbow_colors[col++ % RCC] << *it;
	}
	std::cout << RESET <<std::endl;
}

void	test(void (*f)(size_t count), size_t test_count, bool print_identification)
{
	std::stringstream	buff;
	std::streambuf*		oBuff = std::cout.rdbuf(buff.rdbuf());

	f(test_count);

	std::cout.rdbuf(oBuff);

	std::string	line;
	Count count = {0,0,0};
	while (std::getline(buff, line))
	{
		switch (line[0])
		{
			case ('A'):
				++count.a;
				break ;
			case ('B'):
				++count.b;
				break ;
			case ('C'):
				++count.c;
				break ;
			default:
				break;
		}
		if (print_identification)
			std::cout << line;
	}
	if (print_identification)
		std::cout << std::endl;
	std::cout << "A: " << LIGHTGREEN << count.a << RESET << " | B: " << LIGHTGREEN << count.b << RESET << " | C: " << LIGHTGREEN << count.c << RESET << std::endl;

}

void	test_by_pointer(size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		Base *obj = generate();
		identify(obj);
		delete(obj);
	}
}

void	test_by_reference(size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		Base *obj = generate();
		identify(*obj);
		delete(obj);
	}
}


int	main(int ac, char **av)
{
	bool	print_identification = false;
	size_t	count = 0;

	if (ac == 1)
	{
		std::cout << "usage: ./test [<int> number_of_tests] [<bool> print_identification]" << std::endl;
		return (0);
	}
	if (ac == 3 && (std::string("true").compare(av[2]) == 0 || std::string("TRUE").compare(av[2]) == 0 || std::string("1").compare(av[2]) == 0))
		print_identification = true;

	try	{ count = std::stoi(av[1]); }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; return (1); }

	std::cout << BLUE << "TEST BY POINTER" << RESET << std::endl;
	test(test_by_pointer, static_cast<size_t>(count), print_identification);
	rainbow_print("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	std::cout << BLUE << "TEST BY REFERENCE" << RESET << std::endl;
	test(test_by_reference, static_cast<size_t>(count), print_identification);

	return (0);
}
