/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:32:48 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/07 19:47:32 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

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
