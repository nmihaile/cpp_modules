/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:51:12 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/05 11:44:35 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBookApp.h"

bool	check_main_input(t_input *input, PhoneBook *phonebook)
{
	(void)phonebook;
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
	int index;
	
	if (std::cin.eof())
	{
		std::cout << std::endl;
		input->status = PB_EXIT;
		return (true);
	}
	else if (input->str.length() == 1 && std::isdigit(input->str.at(0)))
	{
		std::stringstream(input->str) >> index;
		if (index <= 0)
			return (input_error(input, std::string("Index should be greater than 0.")), false);
		else if (index <= phonebook->get_contact_count())
		{
			input->status = PB_DISPLAY_CONTACT;
			std::ostringstream oss;
			oss << (index - 1);
			input->str = oss.str();
			return (true);
		}
		else
		{
			std::string msg = "Index should be smaller than ";
			std::ostringstream oss;
			oss << (phonebook->get_contact_count() + 1);
			msg += oss.str() += ".";
			input_error(input, msg);
			return (false);
		}
	}
	else if (input->str.length() > 0)
		input_error(input, "Wrong input, try again.");
	return (false);
}

bool	check_view_input(t_input *input, PhoneBook *phonebook)
{
	(void)phonebook;
	if (std::cin.eof())
		input->status = PB_EXIT;
	return (true);
}
