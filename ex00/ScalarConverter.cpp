/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:14:02 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/20 20:55:04 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


void	ScalarConverter::convert(const std::string& str)
{
	t_scalar	scalar;

	scalar.sc_type = SC_NONE;
	detectLiteralType(str, scalar);

	std::cout << "SC_TYPE: " << scalar.sc_type << std::endl;

	std::cout << "char: ";		printChar(scalar);	std::cout << std::endl;
	std::cout << "int: ";		printInt(scalar);	std::cout << std::endl;
	// std::cout << "float: ";		printInt(scalar);	std::cout << std::endl;
	// std::cout << "double: ";	printInt(scalar);	std::cout << std::endl;
}

const char* ScalarConverter::InvalidCharConversionException::what() const throw()
{
	return ( "stoc: out of range" );
}


/* ************************************************************************** */
/* ************************************************************************** */


const std::string	ScalarConverter::SC_NON_DISPLAYABLE = "Non displayable";
const std::string	ScalarConverter::SC_IMPOSSIBLE = "impossible";
const std::string	ScalarConverter::SC_NANF = "nanf";
const std::string	ScalarConverter::SC_NAN = "nan";

void	ScalarConverter::detectLiteralType(const std::string& str, t_scalar& scalar)
{
	try
	{
		scalar.c = ScalarConverter::stoc(str);
		std::cout << "HALLO" << std::endl;
		scalar.sc_type = SC_CHAR;
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	
	try
	{
		if (scalar.sc_type == SC_NONE)
		{
			scalar.i = std::stoi(str);
			scalar.sc_type = SC_INT;
		}
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	
	try
	{
		if (scalar.sc_type == SC_NONE)
		{
			scalar.f = std::stof(str);
			scalar.sc_type = SC_FLOAT;
		}
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	try
	{
		if (scalar.sc_type == SC_NONE)
		{
			scalar.d = std::stod(str);
			scalar.sc_type = SC_DOUBLE;
		}
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
}

char	ScalarConverter::stoc(const std::string& str)
{
	if (str.empty() || str.length() > 1 || !std::isprint(str[0]))
		throw ( ScalarConverter::InvalidCharConversionException() );
	return ( str[0] );
}


void	ScalarConverter::printChar(const t_scalar& scalar)
{
	switch (scalar.sc_type)
	{
		case (SC_NONE):
			std::cout << "Ups";
			break ;
		case (SC_INVALID):
			std::cout << "Invalid Input";
			break ;
		case (SC_CHAR):
			std::cout << scalar.c;
			break ;
		case (SC_INT):
			if (scalar.i >= ' ' && scalar.i < 127)
				std::cout << static_cast<char>(scalar.i);
			else
				std::cout << ScalarConverter::SC_NON_DISPLAYABLE;
			break ;
		case (SC_FLOAT):
			std::cout << "Ups - Float";
			break ;
		case (SC_DOUBLE):
			std::cout << "Ups - Double";
			break ;
		default:
			std::cout << "Ups - DEFAULT CASE";
			break ;
	}
}

void	ScalarConverter::printInt(const t_scalar& scalar)
{
	switch (scalar.sc_type)
	{
		case (SC_NONE):
			std::cout << "Ups";
			break ;
		case (SC_INVALID):
			std::cout << "Invalid Input";
			break ;
		case (SC_CHAR):
			std::cout << static_cast<int>(scalar.c);
			break ;
		case (SC_INT):
			std::cout << scalar.i;
			break ;
		case (SC_FLOAT):
			std::cout << static_cast<int>(scalar.f);
			break ;
		case (SC_DOUBLE):
			std::cout << static_cast<int>(scalar.d);
			break ;
	}
}

bool	ScalarConverter::isChar(const std::string& str)
{
	if (str.empty())
		return (false);
	if (str.length() == 1 && std::isprint(str[0]))
		return (true);
	return (false);
}
