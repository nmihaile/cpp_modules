/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:14:36 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/17 12:10:47 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define ENABLED_FIXED_DEBUG false

class Fixed
{
public:
	Fixed();
	Fixed(const int32_t i);
	Fixed(const float f);
	Fixed(const Fixed& other);
	~Fixed();

	int32_t				getRawBits(void) const;
	void				setRawBits(int32_t const raw);
	float				toFloat(void) const;
	int32_t 			toInt(void) const;
	
	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

	Fixed&	operator =  (const Fixed& other);
	bool	operator >  (const Fixed& other) const;
	bool	operator <  (const Fixed& other) const;
	bool	operator >= (const Fixed& other) const;
	bool	operator <= (const Fixed& other) const;
	bool	operator == (const Fixed& other) const;
	bool	operator != (const Fixed& other) const;

	Fixed&	operator += (const Fixed& other);
	Fixed&	operator -= (const Fixed& other);
	Fixed&	operator *= (const Fixed& other);
	Fixed&	operator /= (const Fixed& other);

	Fixed	operator +  (const Fixed& other) const;
	Fixed	operator -  (const Fixed& other) const;
	Fixed	operator *  (const Fixed& other) const;
	Fixed	operator /  (const Fixed& other) const;

	Fixed&	operator ++ ();
	Fixed&	operator -- ();
	Fixed	operator ++ (int);
	Fixed	operator -- (int);

private:
	int32_t					m_rawBits;
	static const int32_t	m_precision = 8;

	void	swap(Fixed& other);
};

std::ostream&  operator << (std::ostream& os, const Fixed& other);

#endif
