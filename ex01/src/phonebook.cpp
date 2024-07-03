/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:25:59 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/03 18:05:14 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include "../inc/phonebook.hpp"

PhoneBook::PhoneBook()
{
	m_contact_count = 0;
	m_next = 0;
}

PhoneBook::~PhoneBook()
{	
}

int	PhoneBook::get_contact_count(void)
{
	return (m_contact_count);
}

bool	PhoneBook::add_contact(Contact contact)
{
	if (m_next >= MAX_ENTRIES)
		return (true);
	contacts[m_next] = contact;
	m_next++;
	if (m_next >= MAX_ENTRIES)
		m_next = 0;
	if (m_contact_count < MAX_ENTRIES)
		m_contact_count++;
	return (false);
}

Contact	PhoneBook::get_contact(int i)
{
	Contact empty;
	
	if (i >= MAX_ENTRIES || i > m_contact_count)
		return (empty);
	return (contacts[i]);
}
