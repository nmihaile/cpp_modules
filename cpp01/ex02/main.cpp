/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:44:41 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/07 20:16:45 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

# define LIGHTRED		"\033[0;91m"
# define LIGHTGREEN		"\033[0;92m"
# define LIGHTYELLOW	"\033[0;93m"
# define LIGHTBLUE		"\033[0;94m"
# define LIGHTMAGENTA	"\033[0;95m"
# define LIGHTCYAN		"\033[0;96m"
# define RESET			"\033[0m"

void	print_section(std::string title, std::string color)
{
	std::cout	<< color
				<< "\n--------------------------------\n"
				<< title
				<< "\n--------------------------------" << RESET << std::endl;	
}

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	print_section("Adresses", LIGHTCYAN);
	std::cout << "Address of str           : " << &str			<< std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR		<< std::endl;
	std::cout << "Address held by stringREF: " << &stringREF	<< std::endl;

	print_section("Values", LIGHTGREEN);
	std::cout << "value of str           : " << str			<< std::endl;
	std::cout << "value held by stringPTR: " << *stringPTR	<< std::endl;
	std::cout << "value held by stringREF: " << stringREF	<< std::endl;

	std::cout << std::endl;
	return (0);
}
