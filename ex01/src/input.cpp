/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:39:34 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/03 15:56:57 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook_header.h"

void	input_error(t_input *input, std::string msg)
{
	input->status = PB_ERROR;
	input->error = msg;
}

t_status	getInput(t_input *input, std::string amsg, PhoneBook *phonebook, int (render_menu)(t_input *input, PhoneBook *phonebook, std::string msg), bool (check)(t_input *input, PhoneBook *phonebook))
{
	while (true)
	{
		render_menu(input, phonebook, amsg);
		std::cout << "› ";
		input->printed_lines++;
		std::getline(std::cin, input->str);
		if (check(input, phonebook) == true)
			break ;
	}
	return (input->status);
}
