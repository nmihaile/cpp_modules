/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:38:26 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/01 16:22:40 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/contact.hpp"

Contact::Contact()
{
	
}

Contact::~Contact()
{
	
}

void	Contact::set_first_name(std::string fn)
{
	first_name = fn;
}

std::string	Contact::get_first_name(void)
{
	return (first_name);
}

void	Contact::set_last_name(std::string ln)
{
	last_name = ln;
}

std::string	Contact::get_last_name(void)
{
	return (last_name);
}

void	Contact::set_nickname(std::string nn)
{
	nickname = nn;
}

std::string	Contact::get_nickname(void)
{
	return (nickname);
}

void	Contact::set_phone_number(std::string pn)
{
	phone_number = pn;
}

std::string	Contact::get_phone_number(void)
{
	return (phone_number);
}

void	Contact::set_darkest_secret(std::string ds)
{
	darkest_secret = ds;
}

std::string	Contact::get_darkest_secret(void)
{
	return (darkest_secret);
}
