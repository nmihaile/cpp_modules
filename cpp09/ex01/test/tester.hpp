/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:41:12 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/30 17:03:28 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "../RPN.hpp"

#define GRAY			"\033[90m"
#define BLUE			"\033[34m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

size_t		test_count(bool do_count);
size_t		test_passed(bool do_count);
std::string	replace_underscores(std::string str);
void		print_test_result(std::string msg, std::string expected);
void		print_test_result(void);

std::string	captureStdout(void (*test_func)(void));

void		test(std::string expression, std::string expected);

#endif
