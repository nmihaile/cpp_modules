/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:14:36 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/13 20:37:59 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copy constructor
// Copy assignment operator
// copy-and-swap idiom
// https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();

	Fixed& operator = (const Fixed &other);

	int32_t	getRawBits(void) const;
	void	setRawBits(int32_t const raw);

private:
	int32_t					m_rawBits;
	static const int32_t	m_precision = 8;

	void		swap(Fixed &other);
};

#endif
