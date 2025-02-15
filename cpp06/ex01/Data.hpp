/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:33:51 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/08 15:26:55 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DATA_HPP
#define DATA_HPP

#include <string>

typedef struct s_data
{
	std::string		key;
	std::string		value;

}	Data;

#endif