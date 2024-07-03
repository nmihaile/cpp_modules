/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:38:21 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/01 16:22:44 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	Contact();
	Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) : first_name(fn), last_name(ln), nickname(nn), phone_number(pn), darkest_secret(ds) {};
	~Contact();

	void		set_first_name(std::string fn);
	std::string	get_first_name(void);
	void		set_last_name(std::string ln);
	std::string	get_last_name(void);
	void		set_nickname(std::string nn);
	std::string	get_nickname(void);
	void		set_phone_number(std::string pn);
	std::string	get_phone_number(void);
	void		set_darkest_secret(std::string ds);
	std::string	get_darkest_secret(void);
};

#endif
