/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:25:58 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/03 18:05:29 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

# define MAX_ENTRIES 8

class PhoneBook
{
private:
	int		m_contact_count;
	int		m_next;
	Contact contacts[MAX_ENTRIES];

public:	
	PhoneBook();
	~PhoneBook();

	int		get_contact_count(void);
	bool	add_contact(Contact contact);
	Contact	get_contact(int i);
};

#endif