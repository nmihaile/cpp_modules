/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:14:03 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/20 21:39:22 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <exception>

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

private:
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

	static void			detectLiteralType(const std::string& str, t_scalar& scalar);
	
	static char			stoc(const std::string& str);
	static void			printChar(const t_scalar& scalar);
	static void			printInt(const t_scalar& scalar);

	static bool			isChar(const std::string& str);

};

#endif
