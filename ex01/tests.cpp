/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:10:27 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/13 16:24:03 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void	set_uid(int& i)
{
	static int count;
	i = count++;
}

static void	timesTwo(int& i)
{
	i *= 2;
}

void	test_int_timesTwo(int arr_size)
{
	int	arr[arr_size];

	iter<int>(arr, arr_size, set_uid);
	iter<int>(arr, arr_size, timesTwo);
	iter<int>(arr, arr_size, print_inline_item<int>);
}

/* ************************************************************************** */
/* ************************************************************************** */

static void	capitalize(std::string& str)
{
	for (std::string::iterator it = str.begin(); it < str.end(); ++it)
		*it = std::toupper(*it);
}

void	test_string_capitalize(int arr_size)
{
	arr_size = 5;
	std::string arr[5] = {
		"hallo",
		"world",
		"where",
		"are",
		"you"
	};

	iter<std::string>(arr, arr_size, capitalize);
	iter<std::string>(arr, arr_size, print_inline_item<std::string>);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	test_array_size_zero(int arr_size)
{
	int arr[arr_size];

	iter<int>(arr, arr_size, set_uid);
	iter<int>(arr, arr_size, timesTwo);
	iter<int>(arr, arr_size, print_inline_item<int>);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	test_array_size_one(int arr_size)
{
	int arr[arr_size];

	arr[0] = 42;
	iter<int>(arr, arr_size, timesTwo);
	iter<int>(arr, arr_size, print_inline_item<int>);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	test_NULL_array(int arr_size)
{
	iter<int>(nullptr, arr_size, set_uid);
}

/* ************************************************************************** */
/* ************************************************************************** */

static void	set_to_five(int& i)
{
	i = 5;
}

void	test_array_same_values(int arr_size)
{
	int arr[arr_size];

	iter<int>(arr, arr_size, set_to_five);
	iter<int>(arr, arr_size, timesTwo);
	iter<int>(arr, arr_size, print_inline_item<int>);
}
