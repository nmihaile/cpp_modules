/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:05:52 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/08 12:52:30 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon(void);
	Weapon(const std::string type);
	~Weapon(void);

	void				setType(const std::string type);
	const std::string	getType(void);

private:
	std::string	m_type;	
};

#endif