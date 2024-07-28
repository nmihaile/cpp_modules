/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:13:10 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 20:47:11 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "debug.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define MATERIA_TEMPLATE_SIZE 4

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	~MateriaSource();

	MateriaSource& operator = (MateriaSource& other);

	virtual void		learnMateria(AMateria* m);
	virtual AMateria*	createMateria(std::string const & type);

private:
	AMateria*	m_template[MATERIA_TEMPLATE_SIZE];
};

#endif
