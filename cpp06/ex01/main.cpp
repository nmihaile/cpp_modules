/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:47:35 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/08 16:04:02 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Serializer.hpp"
#include "Data.hpp"

#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

#define __func_width__ 25

Data*	createData(const std::string key, const std::string value)
{
	Data* data = new Data;
	data->key = key;
	data->value = value;
	return (data);
}

bool	check(Data* one, Data* two)
{
	return (one->key == two->key && one->value == two->value);
}

size_t	count(bool counts)
{
	static size_t	count;
	if (counts)
		std::cout << LIGHTCYAN << "[" << std::setw(2) << std::right << std::setfill('0') << ++count << "] " << RESET;
	return (count);
}

size_t	passed(bool passed)
{
	static size_t	count;
	if (passed)
		 ++count;
	return (count);
}

int	print_test_result()
{
	std::cout << std::endl;
	if (count(false) == passed(false))
	{
		std::cout << "  🎉🥳 All " << std::setw(2) << count(false) <<" tests passed! 🥳🎉" << std::endl;
		std::cout << LIGHTGREEN << "══════════════════════════════════" << RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << "  ❌ " << passed(false) << "/" << count(false) << " tests passed!" << std::endl;
		std::cout << "     please investigate and debug acordingly…" << std::endl;
		std::cout << LIGHTRED << "══════════════════════════════════════════════════" << RESET << std::endl;
		return (1);
	}
}

void test(bool (*f)(void))
{
	count(true);
	
	if ( f() == true )
	{
		passed(true);
		std::cout << " -> " << LIGHTGREEN << "[OK]";
	}
	else
		std::cout << " -> " << LIGHTRED << "[KO]";
		
	std::cout << RESET << std::endl;
}


/* ************************************************************************** */
/* TESTS																	  */
/* ************************************************************************** */


bool serialize_cmp_adr(void)
{
	std::cout << std::setw(__func_width__) << std::left << std::setfill(' ') << __func__;
	bool		result;

	Data*		data = createData("What is the Answer to the Ultimate Question of Life, the Universe, and Everything?", "42");
	uintptr_t	ptr;

	ptr = Serializer::serialize(data);

	result = (reinterpret_cast<uintptr_t>(data) == ptr);

	delete(data);
	return (result);
}

bool deserialize_cmp_adr(void)
{
	std::cout << std::setw(__func_width__) << std::left << std::setfill(' ') << __func__;
	bool		result;

	Data*		data = createData("What is the Answer to the Ultimate Question of Life, the Universe, and Everything?", "42");
	uintptr_t	ptr;
	Data*		copy;

	ptr = Serializer::serialize(data);
	copy = Serializer::deserialize(ptr);

	result = (data == copy);

	delete(data);
	return (result);
}

bool change_origininal_data(void)
{
	std::cout << std::setw(__func_width__) << std::left << std::setfill(' ') << __func__;
	bool		result;

	Data*		data = createData("What is the Answer to the Ultimate Question of Life, the Universe, and Everything?", "0");
	uintptr_t	ptr;
	Data*		copy;

	ptr = Serializer::serialize(data);
	copy = Serializer::deserialize(ptr);

	data->value = "42";

	result = check(data, copy);

	delete(data);
	return (result);
}

bool change_copied_data(void)
{
	std::cout << std::setw(__func_width__) << std::left << std::setfill(' ') << __func__;
	bool		result;

	Data*		data = createData("What is the Answer to the Ultimate Question of Life, the Universe, and Everything?", "0");
	uintptr_t	ptr;
	Data*		copy;

	ptr = Serializer::serialize(data);
	copy = Serializer::deserialize(ptr);

	copy->value = "42";

	result = check(data, copy);

	delete(data);
	return (result);
}


/* ************************************************************************** */
/* MAIN																		  */
/* ************************************************************************** */


int	main(void)
{
	test(serialize_cmp_adr);
	test(deserialize_cmp_adr);
	test(change_origininal_data);
	test(change_copied_data);

	return (print_test_result());
}
