/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:02:15 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/07 18:37:15 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*z;

	z = new Zombie [N];
	for (int i = 0; i < N; i++)
		z[i].set_name(name);
	return (z);
}
