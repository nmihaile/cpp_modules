/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:32:48 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/08 11:18:38 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define DEBUG_INFO

class Zombie
{
private:
	std::string	m_name;
	
public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	
	void	set_name(std::string new_name);
	void	announce(void);
};

Zombie*	zombieHorde( int N, std::string name );

#endif
