/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:51:12 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/03 17:57:52 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook_header.h"

bool	check_main_input(t_input *input, PhoneBook *phonebook)
{
	if (capitalize(input->str) == "EXIT")
	{
		input->status = PB_EXIT;
		return (true);
	}
	else if (std::cin.eof())
	{
		std::cout << std::endl;
		input->status = PB_EXIT;
		return (true);
	}
	else if (capitalize(input->str) == "ADD")
	{
		input->status = PB_ADD;
		return (true);
	}
	else if (capitalize(input->str) == "SEARCH")
	{
		input->status = PB_SEARCH;
		return (true);
	}
	else if (input->str.length() > 0)
		input_error(input, "Wrong input, try again.");
	return (false);
}

bool	check_search_input(t_input *input, PhoneBook *phonebook)
{
	if (std::cin.eof())
	{
		std::cout << std::endl;
		input->status = PB_EXIT;
		return (true);
	}
	else if (input->str.length() == 1 && std::isdigit(input->str.at(0)))
	{
		if (std::stoi(input->str) <= 0)
			return (input_error(input, std::string("Index should be greater than 0.")), false);
		else if (std::stoi(input->str) <= phonebook->get_contact_count())
		{
			input->status = PB_DISPLAY_CONTACT;
			input->str = std::to_string(std::stoi(input->str) - 1);
			return (true);
		}
		else
			return (input_error(input, std::string("Index should be smaller than ") += std::to_string(phonebook->get_contact_count() + 1) += "." ), false);
	}
	else if (input->str.length() > 0)
		input_error(input, "Wrong input, try again.");
	return (false);
}

bool	check_view_input(t_input *input, PhoneBook *phonebook)
{
	if (std::cin.eof())
		input->status = PB_EXIT;
	return (true);
}
