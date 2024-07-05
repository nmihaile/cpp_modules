/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:53:40 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/05 11:44:51 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBookApp.h"

static bool	ft_isspace(int c)
{
	std::string	space;

	space = "\t\n\v\f\r ";
	for (std::string::iterator it = space.begin(); it < space.end(); ++it)
		if (c == *it)
			return (true);
	return (false);
}

std::string	capitalize(std::string str)
{
	for (std::string::iterator it = str.begin(); it < str.end(); it++)
		*it = std::toupper(*it);
	return (str);
}

std::string	truncate(std::string str, size_t size)
{
	std::string	trunc;
	if (str.length() <= size)
		return (str);
	trunc = str.substr(0, size - 1) + ".";
	return (trunc);
}

std::string	trim_whitespaces(std::string str)
{
	std::size_t start = 0;
	while (start < str.size() && ft_isspace(str.at(start)))
		start++;
	std::size_t end = str.size();
	while (end > start && ft_isspace(str.at(end - 1)))
		end--;
	
	std::string trimmed = str.substr(start, end - start);
	
	std::string result;
	bool		in_whitespace = false;
	for (std::string::iterator it = trimmed.begin(); it < trimmed.end(); it++)
	{
		if (ft_isspace(*it))
		{
			if (in_whitespace == false)
			{
				result += ' ';
				in_whitespace = true;
			}
		}
		else
		{
			result += *it;
			in_whitespace = false;
		}
	}
	
	return (result);
}
