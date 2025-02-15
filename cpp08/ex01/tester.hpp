/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:28:53 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/20 10:35:30 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#define BLUE			"\033[34m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

#define TEST(func, expected) test(func, expected, #func)

size_t		test_count(bool do_count);
size_t		test_passed(bool do_count);
std::string	replace_underscores(std::string str);
void		print_test_result(std::string msg, std::string expected);
void		print_test_result(void);
void		test(void (*test_func)(void), std::string expected, const std::string& funcName);

#endif
