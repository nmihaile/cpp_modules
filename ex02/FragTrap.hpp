/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:57:47 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/20 21:33:21 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap& other);
	~FragTrap();

	void		highFivesGuys(void);
	FragTrap&	operator = (const FragTrap& other);

private:
	void	init(void);
	
};

#endif
