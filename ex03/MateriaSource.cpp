/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:13:09 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 21:14:33 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	log(DEBUG_LOG, "MateriaSource default constructor called.");

	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
		m_template[idx] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	log(DEBUG_LOG, "MateriaSource copy constructor called.");

	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
		if (other.m_template[idx])
			m_template[idx] = other.m_template[idx]->clone();
		else
			m_template[idx] = NULL;
}

MateriaSource::~MateriaSource()
{
	log(DEBUG_LOG, "MateriaSource destructor called.");

	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
		if (m_template[idx])
			delete(m_template[idx]);
}


MateriaSource& MateriaSource::operator = (MateriaSource& other)
{
	log(DEBUG_LOG, "MateriaSource copy assignement operator overload called.");

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
	{
		log(WARNING_LOG, "MateriaSource learnMateria failed: materia is NULL");
		return ;
	}
		
	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
		if (m_template[idx] == NULL)
		{
			log(INFO_LOG, "MateriaSource adds " + m->getType() + "-template in slot " + ft_itostring(idx));
			m_template[idx] = m;
			return ;
		}
	delete(m);
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int idx = 0; idx < MATERIA_TEMPLATE_SIZE; idx++)
		if (m_template[idx] && m_template[idx]->getType() == type)
		{
			log(INFO_LOG, "MateriaSource creates " + type + " from slot " + ft_itostring(idx));
			return ( m_template[idx]->clone() );
		}
	return (NULL);
}
