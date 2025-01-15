/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:44:59 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/15 15:59:54 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TESTER_HPP
#define TESTER_HPP

#include <cstddef>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Array.hpp"

#define BLUE			"\033[34m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

size_t	test_count(bool do_count);
size_t	test_passed(bool do_count);
void	print_test_result(std::string msg);

#include "tester.tpp"

#endif
