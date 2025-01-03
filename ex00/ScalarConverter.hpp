/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:14:03 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/03 18:20:29 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>	// std::setprecision
// #include <cctype>
#include <exception>
#include <cmath>	// for nan, nanf, inff, inf

class ScalarConverter
{
public:
	~ScalarConverter();

	static void	convert(const std::string& str);

	class OutOfRangeCharException : public std::exception {
		const char* what() const throw() override;
	};

	class NoConversionCharException : public std::exception {
		const char* what() const throw() override;
	};

	class NoConversionIntException : public std::exception {
		const char* what() const throw() override;
	};

	class NoConversionFloatException : public std::exception {
		const char* what() const throw() override;
	};

	class NoConversionDoubleException : public std::exception {
		const char* what() const throw() override;
	};

private:
	static const std::string	SC_INVALID_INPUT;
	static const std::string	SC_NON_DISPLAYABLE;
	static const std::string	SC_IMPOSSIBLE;
	static const std::string	SC_NANF;
	static const std::string	SC_NAN;

	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& other) = delete;
	ScalarConverter&	operator=(const ScalarConverter& rhs) = delete;

	typedef enum e_sc_type
	{
		SC_NONE,
		SC_INVALID,
		SC_CHAR,
		SC_INT,
		SC_FLOAT,
		SC_DOUBLE
	}	t_sc_type;

	typedef struct s_scalar
	{
		t_sc_type	sc_type;
		char		c;
		int			i;
		float		f;
		double		d;
	}	t_scalar;

	static void		detectLiteralType(const std::string& str, t_scalar& scalar);
	
	static char		stoc(const std::string& str);

	static void		printChar(const t_scalar& scalar);
	static void		printInt(const t_scalar& scalar);
	static void		printFloat(const t_scalar& scalar);
	static void		printDouble(const t_scalar& scalar);

	static bool		isNonPrintable(const std::string& str);
	static bool		isChar(const std::string& str, char& c);
	static bool		isInt(const std::string& str, int& i);
	static bool		isFloat(const std::string& str, float& f);
	static bool		isDouble(const std::string& str, double& d);

	// static bool			isChar(const std::string& str);

};

#endif
