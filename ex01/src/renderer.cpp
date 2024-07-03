/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:20:00 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/03 17:42:46 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook_header.h"

void	clear_lines(int	size)
{
	for (int i = 0; i < size; i++)
		std::cout << ERASE_LINE << MOVE_UP << ERASE_LINE;
}

static void render_line(std::string c1, std::string c2, std::string c3, std::string color)
{
	std::cout << color << c1;
	for (int x = 1; x < WIDTH - 1; x++)
		std::cout << c2;
	std::cout << c3 << RESET << std::endl;
}

static void render_txt_center(std::string c1, std::string msg, std::string c3, std::string txtColor, std::string bgColor)
{
	int paddingLeft;
	int paddingRight;
	
	paddingLeft = (WIDTH - msg.length()) / 2;
	paddingRight = WIDTH - msg.length() - paddingLeft;
	std::cout << bgColor << c1;
	for (int x = 1; x < paddingLeft; x++)
		std::cout << " ";
	std::cout << txtColor << msg;
	for (int x = 1; x < paddingRight; x++)
		std::cout << " ";
	std::cout << bgColor << c3 << RESET << std::endl;
}

static void	render_header(t_input *input)
{
	clear_lines(input->printed_lines);
	input->printed_lines = 0;
	render_line("┌", "─", "╖", LIGHTRED);
	render_line("│", " ", "║", LIGHTRED);
	render_txt_center("│", "welcome to", "║", LIGHTGREEN, LIGHTRED);
	render_txt_center("│", "your darkest phonebook", "║", LIGHTGREEN, LIGHTRED);
	render_line("│", " ", "║", LIGHTRED);
	input->printed_lines += 5;
}

static void render_msg(std::string msg, std::string color, t_input *input)
{
	if (msg.length() > 0)
	{
		render_txt_center("│", msg, "║", color, LIGHTRED);
		render_line("│", " ", "║", LIGHTRED);
		input->printed_lines += 2;
	}	
}

static void	render_error_msg(t_input *input)
{
	render_msg(input->error, LIGHTRED, input);
	input->error = "";
}

static void	render_contact_line(t_input *input, int i, Contact contact)
{
	if (i == 0)
		std::cout << LIGHTRED << "├────────────┬────────────┬────────────┬────────────╢" << std::endl;
	else
		std::cout << LIGHTRED << "├────────────┼────────────┼────────────┼────────────╢" << std::endl;
	std::cout << LIGHTRED << "│ " << RESET << std::setw(10) << (i + 1) << " ";
	std::cout << LIGHTRED << "│ " << LIGHTCYAN << std::setw(10) << truncate(contact.get_first_name(), 10) << " ";
	std::cout << LIGHTRED << "│ " << LIGHTCYAN << std::setw(10) << truncate(contact.get_last_name(), 10) << " ";
	std::cout << LIGHTRED << "│ " << LIGHTCYAN << std::setw(10) << truncate(contact.get_nickname(), 10) << LIGHTRED << " ║" << std::endl;
	input->printed_lines += 2;
}

int	render_phonebook(t_input *input, PhoneBook *phonebook, std::string msg)
{
	render_header(input);
	render_msg(msg, RESET, input);
	render_error_msg(input);
	render_line("╘", "═", "╝", LIGHTRED);
	input->printed_lines += 1;
	return (input->printed_lines);
}

int	render_searchbook(t_input *input, PhoneBook *phonebook, std::string msg)
{
	render_header(input);

	for (int i = 0; i < phonebook->get_contact_count(); ++i)
		render_contact_line(input, i, phonebook->get_contact(i));
	std::cout << LIGHTRED << "├────────────┴────────────┴────────────┴────────────╢" << std::endl;
	render_line("│", " ", "║", LIGHTRED);
	input->printed_lines += 2;

	render_msg(msg, RESET, input);
	render_error_msg(input);
	render_line("╘", "═", "╝", LIGHTRED);
	input->printed_lines += 1;
	return (input->printed_lines);
}

int	render_contact(t_input *input, PhoneBook *phonebook, std::string msg)
{
	Contact	contact;
	
	render_header(input);

	contact = phonebook->get_contact(input->str.at(0) - 48);
	std::cout << LIGHTRED << "├────────────────┬──────────────────────────────────╢" << std::endl;
	std::cout << LIGHTRED << "│ First Name     │ " << LIGHTCYAN << align_left_into(contact.get_first_name(), 32) << LIGHTRED << " ║" << std::endl;
	std::cout << LIGHTRED << "├─              ─┼─                                ─╢" << std::endl;
	std::cout << LIGHTRED << "│ Last Name      │ " << LIGHTCYAN << align_left_into(contact.get_last_name(), 32) << LIGHTRED << " ║" << std::endl;
	std::cout << LIGHTRED << "├─              ─┼─                                ─╢" << std::endl;
	std::cout << LIGHTRED << "│ Nickname       │ " << LIGHTCYAN << align_left_into(contact.get_nickname(), 32) << LIGHTRED << " ║" << std::endl;
	std::cout << LIGHTRED << "├─              ─┼─                                ─╢" << std::endl;
	std::cout << LIGHTRED << "│ Phone Number   │ " << LIGHTCYAN << align_left_into(contact.get_phone_number(), 32) << LIGHTRED << " ║" << std::endl;
	std::cout << LIGHTRED << "├─              ─┼─                                ─╢" << std::endl;
	std::cout << LIGHTRED << "│ Darkest Secret │ " << LIGHTCYAN << align_left_into(contact.get_darkest_secret(), 32) << LIGHTRED << " ║" << std::endl;
	std::cout << LIGHTRED << "├────────────────┴──────────────────────────────────╢" << std::endl;
	render_line("│", " ", "║", LIGHTRED);
	input->printed_lines += 12;

	render_msg(msg, RESET, input);
	render_error_msg(input);
	render_line("╘", "═", "╝", LIGHTRED);
	input->printed_lines += 1;
	return (input->printed_lines);
}
