/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:14:36 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/13 12:58:22 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copy constructor
// Copy assignment operator
// copy-and-swap idiom
// https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed& operator = (const Fixed &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int 	toInt(void) const;

private:
	int					m_rawBits;
	static const int	m_precision = 8;

	void		swap(Fixed &other);
};

std::ostream&  operator << (std::ostream &os, const Fixed &other);

#endif
