/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:27:03 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 18:08:10 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef I_CHARACTER_HPP
#define I_CHARACTER_HPP

#include <string>

// Circular reference
class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {}

	virtual const std::string&	getName() const		=0;
	virtual void				equip(AMateria *m)	=0;
	virtual void				unequip(int idx)	=0;
	virtual void				use(int idx, ICharacter& target) =0;
};

#endif
