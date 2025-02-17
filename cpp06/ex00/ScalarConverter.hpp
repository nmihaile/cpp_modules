/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:14:03 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/08 11:59:48 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>		// std::setprecision
#include <limits>		// for nan, nanf, inff, inf, digits10
#include <cmath>		// fmod
#include <exception>
#include <stdexcept>

#define SC_LIGHTRED			"\033[1;91m"
#define SC_LIGHTGREEN		"\033[1;92m"
#define SC_LIGHTCYAN		"\033[1;96m"
#define SC_RESET			"\033[0m"

class ScalarConverter
{
public:
	~ScalarConverter();

	static void	convert(const std::string& str);

	class NoConversionCharException : public std::exception {
		public: const char* what() const throw() override;
	};

	class NoConversionIntException : public std::exception {
		public: const char* what() const throw() override;
	};

	class NoConversionFloatException : public std::exception {
		public: const char* what() const throw() override;
	};

	class NoConversionDoubleException : public std::exception {
		public: const char* what() const throw() override;
	};

private:
	static const std::string	SC_NON_DISPLAYABLE;
	static const std::string	SC_IMPOSSIBLE;

	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& other) = delete;
	ScalarConverter&	operator=(const ScalarConverter& rhs) = delete;

	typedef enum e_sc_type
	{
		SC_NONE,
		SC_INVALID,
		SC_ERROR,
		SC_CHAR,
		SC_INT,
		SC_FLOAT,
		SC_DOUBLE
	}	t_sc_type;

	typedef struct s_scalar
	{
		t_sc_type	sc_type;
		union
		{
			double	d;
			float	f;
			int		i;
			char	c;
		}			value;
		int			decimalplaces;
	}				t_scalar;

	static void			detectLiteralType(const std::string& str, t_scalar& scalar);
	
	static void			printChar(const t_scalar& scalar);
	static void			printInt(const t_scalar& scalar);
	static void			printFloat(const t_scalar& scalar);
	static void			printDouble(const t_scalar& scalar);

	static void			detectChar(const std::string& str, t_scalar& scalar);
	static void			detectInt(const std::string& str, t_scalar& scalar);
	static void			detectFloat(const std::string& str, t_scalar& scalar);
	static void			detectDouble(const std::string& str, t_scalar& scalar);

	static void			catchDecimalPlaces(const std::string& str, t_scalar& scalar);
	static void			setPrecisionFloat(const float value_f, const t_scalar& scalar);
	static void			setPrecisionDouble(const double value_d, const t_scalar& scalar);

	static std::string	detectedLiteralColor(t_scalar& scalar, t_sc_type type);
};

#endif
