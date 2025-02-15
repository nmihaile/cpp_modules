/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookApp.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:42:28 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/05 11:45:29 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma	once

#ifndef PHONEBOOKAPP_H
# define PHONEBOOKAPP_H

# include <iostream>
# include <iomanip>
# include <sstream>
# include <iterator>
# include "PhoneBook.hpp"

# define WIDTH 53

# define RED			"\033[0;31m"
# define GREEN			"\033[0;32m"
# define YELLOW			"\033[0;33m"
# define BLUE			"\033[0;34m"
# define MAGENTA		"\033[0;35m"
# define CYAN			"\033[0;36m"
# define LIGHTRED		"\033[0;91m"
# define LIGHTGREEN		"\033[0;92m"
# define LIGHTYELLOW	"\033[0;93m"
# define LIGHTBLUE		"\033[0;94m"
# define LIGHTMAGENTA	"\033[0;95m"
# define LIGHTCYAN		"\033[0;96m"
# define RESET			"\033[0m"

# define MOVE_UP		"\033[A"
# define ERASE_LINE		"\033[2K"

typedef enum e_status
{
	PB_NONE,
	PB_ERROR,
	PB_ADD,
	PB_SEARCH,
	PB_DISPLAY_CONTACT,
	PB_EXIT
}	t_status;

typedef struct s_input
{
	std::string	str;
	std::string	error;
	t_status	status;
	int			printed_lines;
}				t_input;

typedef int (*f_render)(t_input *input, PhoneBook *phonebook, std::string msg);
typedef bool (*f_check)(t_input *input, PhoneBook *phonebook);

bool		check_main_input(t_input *input, PhoneBook *phonebook);
bool		check_search_input(t_input *input, PhoneBook *phonebook);
bool		check_view_input(t_input *input, PhoneBook *phonebook);
void		input_error(t_input *input, std::string msg);
t_status	getInput(t_input *input, std::string amsg, PhoneBook *phonebook, f_render render_menu, f_check check);
bool		is_valid_string(std::string *str, t_input *input);
bool		is_valid_number(std::string *str, t_input *input);
int			execute_cmd(t_input *input, PhoneBook *phonebook);
void		clear_lines(int	size);
int			render_phonebook(t_input *input, PhoneBook *phonebook, std::string msg);
int			render_searchbook(t_input *input, PhoneBook *phonebook, std::string msg);
int			render_contact(t_input *input, PhoneBook *phonebook, std::string msg);
std::string	capitalize(std::string str);
std::string	truncate(std::string str, size_t size);
std::string	trim_whitespaces(std::string str);

#endif
