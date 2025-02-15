/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:10:27 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/13 18:19:56 by nmihaile         ###   ########.fr       */
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

/* ************************************************************************** */
/* ************************************************************************** */

static void	square_float(float& f)
{
	f *= f;
}

void	test_floats(int arr_size)
{
	(void)arr_size;
	float	arr[7] = {0.0f, -1.5f, 3.14f, -1000.0f, 1e6f, std::numeric_limits<float>::infinity(), std::numeric_limits<float>::quiet_NaN()};
	iter<float>(arr, 7, square_float);
	iter<float>(arr, 7, print_inline_item<float>);

}

/* ************************************************************************** */
/* ************************************************************************** */

static void	set_vec2(vec2& v)
{
	static float	_x = 1;

	_x *= 2;
	v.x = _x;
	v.y = 0;
}

static void	rotate_90deg(vec2& v)
{
	static float sin90 = std::sin(M_PI / 2);
	static float cos90 = std::cos(M_PI / 2);

	vec2 n;
	n.x = v.x * cos90 - v.y * sin90;
	n.y = v.x * sin90 + v.y * cos90;

	v.x = n.x;
	v.y = n.y;
}

void	test_custom_type(int arr_size)
{
	vec2	arr[arr_size];

	iter<vec2>(arr, arr_size, set_vec2);
	iter<vec2>(arr, arr_size, rotate_90deg);
	iter<vec2>(arr, arr_size, print_inline_item<vec2>);
}

std::ostream& operator<<(std::ostream& os, const vec2& v)
{
	std::streamsize		oPrecision	= std::cout.precision();
	os << "(" << std::fixed << std::setprecision(2) << v.x << ", " << v.y << ")";
	std::cout.precision(oPrecision);
	return (os);
}
