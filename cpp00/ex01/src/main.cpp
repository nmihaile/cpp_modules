/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:34:20 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/05 11:44:24 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBookApp.h"

void	init_input(t_input *input)
{
	input->status = PB_NONE;
	input->str = "";
	input->error = "";
	input->printed_lines = 0;	
}

int	main(void)
{
	PhoneBook 	phonebook;
	t_input		input;
	
	init_input(&input);
	while (42)
	{
		input.status = PB_NONE;
		if (getInput(&input, "ADD, SEARCH or EXIT", NULL, &render_phonebook, &check_main_input) == PB_ERROR)
			continue ;
		if (input.status == PB_EXIT)
			break ;
		execute_cmd(&input, &phonebook);
	}
	clear_lines(input.printed_lines);
	return (0);
}
