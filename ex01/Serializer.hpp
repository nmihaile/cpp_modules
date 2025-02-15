/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:23:43 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/08 12:27:34 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdlib>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
public:
	~Serializer();

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer() = delete;
	Serializer(const Serializer& other) = delete;
	virtual Serializer&	operator=(const Serializer& rhs) = delete;
};

#endif