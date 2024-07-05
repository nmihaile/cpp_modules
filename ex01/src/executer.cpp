/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:47:48 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/05 11:30:25 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook_header.h"

static bool	capture_string(std::string *dst, std::string msg, t_input *input, PhoneBook *phonebook)
{
	(void)phonebook;
	render_phonebook(input, NULL, msg);
	std::cout << "› ";
	input->printed_lines++;
	while (true)
	{
		std::getline(std::cin, *dst);
		if (is_valid_string(dst, input))
			break ;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (true);
		}
		render_phonebook(input, NULL, msg);
		std::cout << "› ";
		input->printed_lines++;
	}
	return (false);
}

static bool	capture_number(std::string *dst, std::string msg, t_input *input, PhoneBook *phonebook)
{
	(void)phonebook;
	render_phonebook(input, NULL, msg);
	std::cout << "› ";
	input->printed_lines++;
	while (true)
	{
		std::getline(std::cin, *dst);
		if (is_valid_number(dst, input))
			break ;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (true);
		}
		render_phonebook(input, NULL, msg);
		std::cout << "› ";
		input->printed_lines++;
	}
	return (false);
}

static void	capture_contact_details(t_input *input, PhoneBook *phonebook)
{
	std::string	str;
	Contact 	contact;

	if (capture_string(&str, "Enter first name:", input, phonebook))
		return ;
	contact.set_first_name(trim_whitespaces(str));
	
	if (capture_string(&str, "Enter last name:", input, phonebook))
		return ;
	contact.set_last_name(trim_whitespaces(str));

	if (capture_string(&str, "Enter nickname:", input, phonebook))
		return ;
	contact.set_nickname(trim_whitespaces(str));

	if (capture_number(&str, "Enter phone number:", input, phonebook))
		return ;
	contact.set_phone_number(trim_whitespaces(str));
	
	if (capture_string(&str, "Enter darkest secret:", input, phonebook))
		return ;
	contact.set_darkest_secret(trim_whitespaces(str));
	
	if (phonebook->add_contact(contact))
		input_error(input, "The phonebook reached its max capacity.");
}

static void	display_contact(t_input *input, PhoneBook *phonebook)
{
	getInput(input, "Return with any input", phonebook, &render_contact, &check_view_input);
	if (input->status == PB_EXIT)
		std::cout << std::endl;
	input->str = "";
	input->status = PB_NONE;
}

int	execute_cmd(t_input *input, PhoneBook *phonebook)
{
	if (input->status == PB_ADD)
		capture_contact_details(input, phonebook);
	else if (input->status == PB_SEARCH)
	{
		if (phonebook->get_contact_count() > 0)
		{
			if (getInput(input, "Choose by index", phonebook, &render_searchbook, &check_search_input) == PB_DISPLAY_CONTACT)
				if (input->status == PB_DISPLAY_CONTACT)
					display_contact(input, phonebook);
				else
					return (1);
			else
				return (input_error(input, "Wrong input."), 1);
		}
		else
			return (input_error(input, "No contacts to display."), 1);
	}
	return (0);
}
