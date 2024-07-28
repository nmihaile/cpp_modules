/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:13:09 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 19:15:41 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
		m_template[idx] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
		if (other.m_template[idx])
			m_template[idx] = other.m_template[idx]->clone();
		else
			m_template[idx] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
		if (m_template[idx])
			delete(m_template[idx]);
}


MateriaSource& MateriaSource::operator = (MateriaSource& other)
{
	if (this == &other)
		return (*this);

	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
	{
		if (m_template[idx])
			delete(m_template[idx]);
		if (other.m_template[idx])
			m_template[idx] = other.m_template[idx]->clone();
		else
			m_template[idx] = NULL;
	}

	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
		return ;
		
	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
		if (m_template[idx] == NULL)
		{
			m_template[idx] = m;
			return ;
		}
	delete(m);
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
		if (m_template[idx] && m_template[idx]->getType() == type)
			return ( m_template[idx]->clone() );
	return (NULL);
}
