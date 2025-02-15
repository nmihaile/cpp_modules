/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:06:05 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/05 11:44:39 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBookApp.h"

bool	is_valid_string(std::string *str, t_input *input)
{
	if (str->length() == 0)
	{
		input->error = "No input. At least 1 character expected.";
		*str = "";
		return (false);
	}
	for (std::string::iterator it = str->begin(); it < str->end(); ++it)
		if (!(std::isalpha(*it) || *it == ' '))
		{
			input->error = "Invalid characters. Use [A..Z, a..z, space]";
			return (false);
		}
	return (true);
}

bool	is_valid_number(std::string *str, t_input *input)
{
	int	offset;
	
	offset = 0;
	if (str->length() == 0)
	{
		input->error = "No input. At least 1 character expected.";
		*str = "";
		return (false);
	}
	if (str->length() > 1)
		offset = 1;
	if (!(str->at(0) == '+' || str->at(0) == '0'))
	{
		input->error = "Start phone number with + or 0";
		*str = "";
		return (false);
	}
	for (std::string::iterator it = str->begin() + offset; it < str->end(); ++it)
		if (!(std::isdigit(*it) || *it == ' '))
		{
			input->error = "Invalid characters. Use [1..9, space]";
			return (false);
		}
	return (true);
}
