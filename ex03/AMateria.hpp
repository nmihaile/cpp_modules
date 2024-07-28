/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:20:44 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 20:44:32 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>
#include <iostream>
#include "debug.hpp"

// Circular reference
class ICharacter;

class AMateria
{
public:	
	AMateria();
	AMateria(const AMateria& other);
	AMateria(std::string const & type);
	virtual ~AMateria();

	AMateria&	operator = (const AMateria& other);
	
	virtual AMateria*	clone() const =0;
	virtual void		use(ICharacter& target);

	const std::string&	getType() const; //Returns the materia type

protected:
	std::string	m_type;
};

#endif
