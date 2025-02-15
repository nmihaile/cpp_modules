/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:14:35 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/17 19:58:28 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : m_rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int32_t i) : m_rawBits(i << m_precision)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : m_rawBits(roundf(f * (1 << m_precision)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : m_rawBits(other.m_rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/* ************************************************************************** */
/* ************************************************************************** */


Fixed& Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &other)
		return (*this);

	Fixed tmp(other);
	this->swap(tmp);
	return (*this);
}

int32_t	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (m_rawBits);
}

void	Fixed::setRawBits(int32_t const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	m_rawBits = raw;	
}

float	Fixed::toFloat( void ) const
{
	return ( static_cast<float>(m_rawBits) / static_cast<float>(1 << m_precision) );
}

int32_t 	Fixed::toInt(void) const
{
	return ( m_rawBits >> m_precision );
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Fixed::swap(Fixed &other)
{
	int	tmp = m_rawBits;
	m_rawBits = other.m_rawBits;
	other.m_rawBits = tmp;
}


/* ************************************************************************** */
/* ************************************************************************** */


std::ostream&  operator << (std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
