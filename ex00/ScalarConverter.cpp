/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:14:02 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/08 12:01:40 by nmihaile         ###   ########.fr       */
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
	scalar.decimalplaces = 0;

	try
	{
		detectLiteralType(str, scalar);
	}
	catch(const std::exception& e)
	{
		std::cout << SC_LIGHTRED << "ERROR: " << SC_RESET << e.what() << std::endl;
		return ;
	}
	
	std::cout << detectedLiteralColor(scalar, SC_CHAR)		<< "char: " << SC_RESET;	printChar(scalar);		std::cout << std::endl;
	std::cout << detectedLiteralColor(scalar, SC_INT)		<< "int: " << SC_RESET;		printInt(scalar);		std::cout << std::endl;
	std::cout << detectedLiteralColor(scalar, SC_FLOAT)		<< "float: " << SC_RESET;	printFloat(scalar);		std::cout << std::endl;
	std::cout << detectedLiteralColor(scalar, SC_DOUBLE)	<< "double: " << SC_RESET;	printDouble(scalar);	std::cout << std::endl;
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


const std::string	ScalarConverter::SC_NON_DISPLAYABLE = "Non displayable";
const std::string	ScalarConverter::SC_IMPOSSIBLE = "impossible";

void	ScalarConverter::detectLiteralType(const std::string& str, t_scalar& scalar)
{

	if (str.empty())
	{
		throw ( std::invalid_argument("Invalid argument: empty string") );
		return ;
	}

	try
	{
		ScalarConverter::detectChar(str, scalar);
		scalar.sc_type = SC_CHAR;
		return ;
	}
	catch(const std::out_of_range& e) {
		scalar.sc_type = SC_ERROR;
		throw ;
	}
	catch(...) { }

	try
	{
		if (scalar.sc_type == SC_NONE)
		{
			ScalarConverter::detectInt(str, scalar);
			scalar.sc_type = SC_INT;
			return ;
		}
	}
	catch(...) { }

	try
	{
		if (scalar.sc_type == SC_NONE)
		{
			ScalarConverter::detectFloat(str, scalar);
			scalar.sc_type = SC_FLOAT;
			return ;
		}
	}
	catch(...) { }

	try
	{
		if (scalar.sc_type == SC_NONE)
		{
			ScalarConverter::detectDouble(str, scalar);
			scalar.sc_type = SC_DOUBLE;
			return ;
		}
	}
	catch(...) { }

	if (scalar.sc_type == SC_NONE)
		throw ( std::invalid_argument("Invalid input") );
	
}

void	ScalarConverter::printChar(const t_scalar& scalar)
{
	switch (scalar.sc_type)
	{
		case (SC_CHAR):
			std::cout << "'" << scalar.value.c << "'";
			break ;
		case (SC_INT):
			if (std::isprint(static_cast<char>(scalar.value.i)))
				std::cout << "'" << static_cast<char>(scalar.value.i) << "'";
			else if (scalar.value.i > std::numeric_limits<char>::max() || scalar.value.i < std::numeric_limits<char>::min())
				std::cout << ScalarConverter::SC_IMPOSSIBLE;
			else
				std::cout << ScalarConverter::SC_NON_DISPLAYABLE;
			break ;
		case (SC_FLOAT):
			if (std::isnan(scalar.value.f) || std::abs(scalar.value.f) == std::numeric_limits<float>::infinity() ||
				scalar.value.f > std::numeric_limits<char>::max() || scalar.value.f < std::numeric_limits<char>::min())
				std::cout << ScalarConverter::SC_IMPOSSIBLE;
			else if (std::isprint(static_cast<char>(scalar.value.f)))
				std::cout << "'" << static_cast<char>(scalar.value.f) << "'";
			else
				std::cout << ScalarConverter::SC_NON_DISPLAYABLE;
			break ;
		case (SC_DOUBLE):
			if (std::isnan(scalar.value.d) || std::abs(scalar.value.d) == std::numeric_limits<double>::infinity() ||
				scalar.value.d > std::numeric_limits<char>::max() || scalar.value.d < std::numeric_limits<char>::min())
				std::cout << ScalarConverter::SC_IMPOSSIBLE;
			else if (std::isprint(static_cast<char>(scalar.value.d)))
				std::cout << "'" << static_cast<char>(scalar.value.d) << "'";
			else
				std::cout << ScalarConverter::SC_NON_DISPLAYABLE;
			break ;
		default:
			std::cout << SC_LIGHTRED<< "UPS <ScalarConverter::printChar()>: something really went wrong!" << SC_RESET;
			break ;
	}
}

void	ScalarConverter::printInt(const t_scalar& scalar)
{
	switch (scalar.sc_type)
	{
		case (SC_CHAR):
			std::cout << static_cast<int>(scalar.value.c);
			break ;
		case (SC_INT):
			std::cout << scalar.value.i;
			break ;
		case (SC_FLOAT):
			if (std::isnan(scalar.value.f) || std::abs(scalar.value.f) == std::numeric_limits<float>::infinity() ||
				scalar.value.f > std::numeric_limits<int>::max() || scalar.value.f < std::numeric_limits<int>::min())
				std::cout << ScalarConverter::SC_IMPOSSIBLE;
			else
				std::cout << static_cast<int>(scalar.value.f);
			break ;
		case (SC_DOUBLE):
			if (std::isnan(scalar.value.d) || std::abs(scalar.value.d) == std::numeric_limits<double>::infinity() ||
				scalar.value.d > std::numeric_limits<int>::max() || scalar.value.d < std::numeric_limits<int>::min())
				std::cout << ScalarConverter::SC_IMPOSSIBLE;
			else
				std::cout << static_cast<int>(scalar.value.d);
			break ;
		default:
			std::cout << SC_LIGHTRED<< "UPS <ScalarConverter::printInt()>: something really went wrong!" << SC_RESET;
			break ;
	}
}

void	ScalarConverter::printFloat(const t_scalar& scalar)
{
	std::streamsize		oPrecision	= std::cout.precision();
	std::ios::fmtflags	oFlags		= std::cout.flags();

	switch (scalar.sc_type)
	{
		case (SC_CHAR):
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(scalar.value.c) << 'f';
			break ;
		case (SC_INT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(scalar.value.i) << 'f';
			break ;
		case (SC_FLOAT):
			ScalarConverter::setPrecisionFloat(scalar.value.f, scalar);
			std::cout << scalar.value.f << 'f';
			break ;
		case (SC_DOUBLE):
			if (std::isinf(scalar.value.d) || std::isnan(scalar.value.d))
			{
				std::cout << static_cast<float>(scalar.value.d) << "f";
				break ;
			}
			if (scalar.value.d > std::numeric_limits<float>::max() || scalar.value.d < std::numeric_limits<float>::lowest())
			{
				std::cout << ScalarConverter::SC_IMPOSSIBLE;
				break ;
			}
			ScalarConverter::setPrecisionFloat(static_cast<float>(scalar.value.d), scalar);
			std::cout << static_cast<float>(scalar.value.d) << "f";
			break ;
		default:
			std::cout << SC_LIGHTRED<< "UPS <ScalarConverter::printFloat()>: something really went wrong!" << SC_RESET;
			break ;
	}

	std::cout.flags(oFlags);
	std::cout.precision(oPrecision);
}

void	ScalarConverter::printDouble(const t_scalar& scalar)
{
	std::streamsize		oPrecision	= std::cout.precision();
	std::ios::fmtflags	oFlags		= std::cout.flags();

	switch (scalar.sc_type)
	{
		case (SC_CHAR):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(scalar.value.c);
			break ;
		case (SC_INT):
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(scalar.value.i);
			break ;
		case (SC_FLOAT):
			ScalarConverter::setPrecisionDouble(static_cast<double>(scalar.value.f), scalar);
			std::cout << static_cast<double>(scalar.value.f);
			break ;
		case (SC_DOUBLE):
			ScalarConverter::setPrecisionDouble(scalar.value.d, scalar);
			std::cout << scalar.value.d;
			break ;
		default:
			std::cout << SC_LIGHTRED<< "UPS <ScalarConverter::printDouble()>: something really went wrong!" << SC_RESET;
			break ;
	}

	std::cout.flags(oFlags);
	std::cout.precision(oPrecision);
}

void	ScalarConverter::detectChar(const std::string& str, t_scalar& scalar)
{
	scalar.value.c = str[0];
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		if ( std::isprint(static_cast<unsigned char>(str[0])) )
			return ;
		throw ( std::out_of_range("conversion to char <" + std::to_string(scalar.value.c) + ">: out of range <32, 126>") );		
	}
	throw ( ScalarConverter::NoConversionCharException() );
}

void	ScalarConverter::detectInt(const std::string& str, t_scalar& scalar)
{
	std::stringstream ss(str);

	ss >> scalar.value.i;
	if ( !ss.fail() && ss.eof() )
		return ;

	throw ( ScalarConverter::NoConversionIntException() );
}

void	ScalarConverter::detectFloat(const std::string& str, t_scalar& scalar)
{
	if (str == "nanf") {
		scalar.value.f = std::numeric_limits<float>::quiet_NaN();
		return ;
	} else if (str == "inff" || str == "+inff") {
		scalar.value.f = std::numeric_limits<float>::infinity();
		return ;
	} else if (str == "-inff") {
		scalar.value.f = -std::numeric_limits<float>::infinity();
		return ;
	} else if (str.find_last_of('.') == std::string::npos) {
		throw ( ScalarConverter::NoConversionFloatException() );
		return ;
	}

	if (str.back() == 'f')
	{
		std::string			num = str.substr(0, str.size() - 1);
		std::stringstream	ss(num);

		ss >> scalar.value.f;
		if (!ss.fail() && ss.eof())
		{
			catchDecimalPlaces(str, scalar);
			return ;
		}
	}

	throw ( ScalarConverter::NoConversionFloatException() );
}

void	ScalarConverter::detectDouble(const std::string& str, t_scalar& scalar)
{
	if (str == "nan") {
		scalar.value.d = std::numeric_limits<double>::quiet_NaN();
		return ;
	} else if (str == "inf" || str == "+inf") {
		scalar.value.d = std::numeric_limits<double>::infinity();
		return ;
	} else if (str == "-inf") {
		scalar.value.d = -std::numeric_limits<double>::infinity();
		return ;
	} else if (str.find_last_of('.') == std::string::npos) {
		throw ( ScalarConverter::NoConversionDoubleException() );
		return ;
	}

	std::stringstream	ss(str);

	ss >> scalar.value.d;
	if (!ss.fail() && ss.eof())
	{
		catchDecimalPlaces(str, scalar);
		return ;
	}

	throw ( ScalarConverter::NoConversionDoubleException() );
}

void	ScalarConverter::catchDecimalPlaces(const std::string& str, t_scalar& scalar)
{
	size_t	pos = 0;

	pos = str.find('.', pos);
	if (pos == std::string::npos)
		return ;
	
	scalar.decimalplaces = str.size() - pos - 1;

	if (str.back() == 'f')
		scalar.decimalplaces--;

	if (scalar.decimalplaces == 0)
		scalar.decimalplaces = 1;
}

void	ScalarConverter::setPrecisionFloat(const float value_f, const t_scalar& scalar)
{
	int	dp = scalar.decimalplaces;

	if (dp >  std::numeric_limits<float>::digits10)
		dp = std::numeric_limits<float>::digits10;
	if (std::fmod(value_f, 1.0) == 0.0f)
		dp = 1;

	std::cout << std::fixed << std::setprecision(dp);
}
	// std::cout << "DP: [" << dp << "] ";

void	ScalarConverter::setPrecisionDouble(const double value_d, const t_scalar& scalar)
{
	int	dp = scalar.decimalplaces;

	if (dp > std::numeric_limits<double>::digits10)
		dp = std::numeric_limits<double>::digits10;
	if (std::fmod(value_d, 1.0) == 0.0)
		dp = 1;

	std::cout << std::fixed << std::setprecision(dp);
}
	// std::cout << "DP: [" << dp << "] ";

std::string	ScalarConverter::detectedLiteralColor(t_scalar& scalar, t_sc_type type)
{
	if (scalar.sc_type == type)
		return (SC_LIGHTGREEN);
	return (SC_RESET);
}
