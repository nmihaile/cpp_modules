/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:53:40 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/03 15:08:27 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook_header.h"

std::string	capitalize(std::string str)
{
	for (std::string::iterator it = str.begin(); it < str.end(); it++)
		*it = std::toupper(*it);
	return (str);
}

std::string	truncate(std::string str, int size)
{
	std::string	trunc;
	if (str.length() <= size)
		return (str);
	trunc = str.substr(0, size - 1) + ".";
	return (trunc);
}

std::string align_left_into(std::string str, int size)
{
	if (str.length() > size)
		return (truncate(str, size));
	else
		return (str +  std::string(size - str.length(), ' '));
}
