/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:14:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/03 18:21:28 by nmihaile         ###   ########.fr       */
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

	if (scalar.sc_type == SC_NONE)
		scalar.sc_type = SC_INVALID;

	// std::cout << "SC_TYPE: " << scalar.sc_type << std::endl;

	std::cout << "char: ";		printChar(scalar);		std::cout << std::endl;
	std::cout << "int: ";		printInt(scalar);		std::cout << std::endl;
	std::cout << "float: ";		printFloat(scalar);		std::cout << std::endl;
	std::cout << "double: ";	printDouble(scalar);	std::cout << std::endl;
}

const char* ScalarConverter::OutOfRangeCharException::what() const throw()
{
	return ( "conversion to char: out of range" );
}


const char* ScalarConverter::NoConversionCharException::what() const throw()
{
	return ( "no conversion to char" );
}

const char* ScalarConverter::NoConversionIntException::what() const throw()
{
	return ( "no conversion to int" );
}

const char* ScalarConverter::NoConversionFloatException::what() const throw()
{
	return ( "no conversion to float" );
}

const char* ScalarConverter::NoConversionDoubleException::what() const throw()
{
	return ( "no conversion to double" );
}

/* ************************************************************************** */
/* ************************************************************************** */


const std::string	ScalarConverter::SC_INVALID_INPUT = "Invalid input";
const std::string	ScalarConverter::SC_NON_DISPLAYABLE = "Non displayable";
const std::string	ScalarConverter::SC_IMPOSSIBLE = "impossible";
const std::string	ScalarConverter::SC_NANF = "nanf";
const std::string	ScalarConverter::SC_NAN = "nan";

void	ScalarConverter::detectLiteralType(const std::string& str, t_scalar& scalar)
{
	try
	{
		// scalar.c = ScalarConverter::stoc(str);
		ScalarConverter::isChar(str, scalar.c);
		scalar.sc_type = SC_CHAR;
	}
	catch(...) {}
	// catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	try
	{
		if (scalar.sc_type == SC_NONE)
		{
			// scalar.i = std::stoi(str);
			ScalarConverter::isInt(str, scalar.i);
			scalar.sc_type = SC_INT;
		}
	}
	catch(...) {}
	// catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	try
	{
		if (scalar.sc_type == SC_NONE)
		{
			// scalar.f = std::stof(str);
			ScalarConverter::isFloat(str, scalar.f);
			scalar.sc_type = SC_FLOAT;
		}
	}
	catch(...) {}
	// catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	try
	{
		if (scalar.sc_type == SC_NONE)
		{
			// scalar.d = std::stod(str);
			ScalarConverter::isDouble(str, scalar.d);
			scalar.sc_type = SC_DOUBLE;
		}
	}
	catch(...) {}
	// catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
}

char	ScalarConverter::stoc(const std::string& str)
{
	if (str.length() > 1)
		throw ( ScalarConverter::NoConversionCharException() );
	if (!std::isprint(str[0]))
		throw ( ScalarConverter::OutOfRangeCharException() );
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
			std::cout << ScalarConverter::SC_INVALID_INPUT;
			break ;
		case (SC_CHAR):
			std::cout << scalar.c;
			break ;
		case (SC_INT):
			if (scalar.i >= ' ' && scalar.i < 127)
			// if (std::isprint(static_cast<char>(scalar.i)))
				std::cout << static_cast<char>(scalar.i);
			else
				std::cout << ScalarConverter::SC_NON_DISPLAYABLE;
			break ;
		case (SC_FLOAT):
			if (std::isnan(scalar.f) || std::isinf(scalar.f))
				std::cout << ScalarConverter::SC_IMPOSSIBLE;
			else if (scalar.f >= ' ' && scalar.f < 127)
				std::cout << static_cast<char>(scalar.f);
			else
				std::cout << ScalarConverter::SC_NON_DISPLAYABLE;
			break ;
		case (SC_DOUBLE):
			if (std::isnan(scalar.d) || std::isinf(scalar.d))
				std::cout << ScalarConverter::SC_IMPOSSIBLE;
			else if (scalar.d >= ' ' && scalar.d < 127)
				std::cout << static_cast<char>(scalar.d);
			else
				std::cout << ScalarConverter::SC_NON_DISPLAYABLE;
			break ;
		default:
			std::cout << "UPS <ScalarConverter::printChar()>: something really went wrong!";
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
			std::cout << ScalarConverter::SC_INVALID_INPUT;
			break ;
		case (SC_CHAR):
			std::cout << static_cast<int>(scalar.c);
			break ;
		case (SC_INT):
			std::cout << scalar.i;
			break ;
		case (SC_FLOAT):
			if (std::isnan(scalar.f) || std::isinf(scalar.f))
				std::cout << ScalarConverter::SC_IMPOSSIBLE;
			else
				std::cout << static_cast<int>(scalar.f);
			break ;
		case (SC_DOUBLE):
			if (std::isnan(scalar.d) || std::isinf(scalar.d))
				std::cout << ScalarConverter::SC_IMPOSSIBLE;
			else
				std::cout << static_cast<int>(scalar.d);
			break ;
		default:
			std::cout << "UPS <ScalarConverter::printInt()>: something really went wrong!";
			break ;
	}
}

void	ScalarConverter::printFloat(const t_scalar& scalar)
{
	switch (scalar.sc_type)
	{
		case (SC_NONE):
			std::cout << "Ups";
			break ;
		case (SC_INVALID):
			std::cout << ScalarConverter::SC_INVALID_INPUT;
			break ;
		case (SC_CHAR):
			// std::cout.setf(std::ios::dec , std::ios::fixed);
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(scalar.c) << 'f';
			break ;
		case (SC_INT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(scalar.i) << 'f';
			break ;
		case (SC_FLOAT):
			std::cout << scalar.f << 'f';
			break ;
		case (SC_DOUBLE):
			std::cout << static_cast<float>(scalar.d) << 'f';
			break ;
		default:
			std::cout << "UPS <ScalarConverter::printFloat()>: something really went wrong!";
			break ;
	}
}

void	ScalarConverter::printDouble(const t_scalar& scalar)
{
	switch (scalar.sc_type)
	{
		case (SC_NONE):
			std::cout << "Ups";
			break ;
		case (SC_INVALID):
			std::cout << ScalarConverter::SC_INVALID_INPUT;
			break ;
		case (SC_CHAR):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(scalar.c);
			break ;
		case (SC_INT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(scalar.i);
			break ;
		case (SC_FLOAT):
			std::cout << static_cast<double>(scalar.f);
			break ;
		case (SC_DOUBLE):
			std::cout << scalar.d;
			break ;
		default:
			std::cout << "UPS <ScalarConverter::printDouble()>: something really went wrong!";
			break ;
	}
}

bool	ScalarConverter::isNonPrintable(const std::string& str)
{
	if (str.length() == 1 && !std::isprint(static_cast<unsigned char>(str[0])))
		return (true);
	return (false);
}

bool	ScalarConverter::isChar(const std::string& str, char& c)
{
	if (str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0]))) {
		c = str[0];
		return (true);
	}
	throw ( ScalarConverter::NoConversionCharException() );
	return (false);
}

bool	ScalarConverter::isInt(const std::string& str, int& i)
{
	if (str.empty())
	{
		throw ( ScalarConverter::NoConversionIntException() );
		return (false);
	}

	int	value;
	std::stringstream ss(str);

	ss >> value;
	if ( !ss.fail() && ss.eof() ) {
		i = value;
		return (true);
	}

	throw ( ScalarConverter::NoConversionIntException() );
	return (false);
}

bool	ScalarConverter::isFloat(const std::string& str, float& f)
{
	if (str == "nanf" || str.empty()) {
		f = NAN;
		return (true);
	} else if (str == "inff") {
		f = INFINITY;
		return (true);
	} else if (str == "-inff") {
		f = -INFINITY;
		return (true);
	} else if (str.find_last_of('.') == std::string::npos) {
		throw ( ScalarConverter::NoConversionFloatException() );
		return (false);
	}

	if (str.back() == 'f')
	{
		float 				value;
		std::string			num = str.substr(0, str.size() - 1);
		std::stringstream	ss(num);

		ss >> value;
		if (!ss.fail() && ss.eof())
		{
			f = value;
			return (true);
		}
	}

	throw ( ScalarConverter::NoConversionFloatException() );
	return (false);
}

bool	ScalarConverter::isDouble(const std::string& str, double& d)
{
	if (str == "nan" || str.empty()) {
		d = NAN;
		return (true);
	} else if (str == "inf") {
		d = INFINITY;
		return (true);
	} else if (str == "-inf") {
		d = -INFINITY;
		return (true);
	} else if (str.find_last_of('.') == std::string::npos) {
		throw ( ScalarConverter::NoConversionDoubleException() );
		return (false);
	}

	double 				value;
	std::stringstream	ss(str);

	ss >> value;
	if (!ss.fail() && ss.eof())
	{
		d = value;
		return (true);
	}

	throw ( ScalarConverter::NoConversionDoubleException() );
	return (false);
}
