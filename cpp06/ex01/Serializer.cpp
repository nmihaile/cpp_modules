/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:23:41 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/08 12:51:50 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::~Serializer()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


uintptr_t	Serializer::serialize(Data* ptr)
{
	return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return ( reinterpret_cast<Data*>(raw) );
}

