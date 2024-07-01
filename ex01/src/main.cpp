/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:34:20 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/01 11:24:06 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook_header.h"

int	main(void)
{
	Contact c("foo", "bar", "nick", "01", "sec");
	
	// c.first_name = "John Dow";
	
	std::cout << c.first_name << std::endl;

	return (0);
}
