/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:56:18 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/16 10:54:22 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TESTER_HAPP
#define TESTER_HAPP

#include <iostream>
#include <iomanip>
#include <limits>
#include "whatever.hpp"

#define BLUE			"\033[34m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

typedef enum e_color
{
	BLACK,
	WHITE
}	t_color;

size_t	test(std::string descr, bool success);

#include "tester.tpp"

void	runTests();

#endif
