/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:41:42 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 21:02:43 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <string>
#include <iostream>
#include <sstream>

#define LIGHTGRAY		"\033[97m"
#define DARKGRAY		"\033[90m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTYELLOW		"\033[93m"
#define LIGHTBLUE		"\033[94m"
#define LIGHTMAGENTA	"\033[95m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

typedef enum e_debug_type
{
	DEBUG_LOG,
	INFO_LOG,
	WARNING_LOG,
	ERROR_LOG
}	t_debug_type;

std::string	ft_itostring(int i);
void		log(t_debug_type dt, std::string msg);

#endif
