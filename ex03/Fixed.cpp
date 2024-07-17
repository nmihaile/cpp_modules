/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:14:35 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/17 12:02:42 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : m_rawBits(0)
{
#if ENABLED_FIXED_DEBUG
	std::cout << "Default constructor called" << std::endl;
#endif
}

Fixed::Fixed(const int32_t i) : m_rawBits(i << m_precision)
{
#if ENABLED_FIXED_DEBUG
	std::cout << "Int constructor called" << std::endl;
#endif
}

Fixed::Fixed(const float f) : m_rawBits(std::roundf(f * (1 << m_precision)))
{
#if ENABLED_FIXED_DEBUG
	std::cout << "Float constructor called" << std::endl;
#endif
}

Fixed::Fixed(const Fixed &other) : m_rawBits(other.m_rawBits)
{
#if ENABLED_FIXED_DEBUG
	std::cout << "Copy constructor called" << std::endl;
#endif
}

Fixed::~Fixed()
{
#if ENABLED_FIXED_DEBUG
	std::cout << "Destructor called" << std::endl;
#endif
}


/* ************************************************************************** */
/* ************************************************************************** */


int32_t	Fixed::getRawBits(void) const
{
#if ENABLED_FIXED_DEBUG
	std::cout << "getRawBits member function called" << std::endl;
#endif

	return (m_rawBits);
}

void	Fixed::setRawBits(int32_t const raw)
{
#if ENABLED_FIXED_DEBUG
	std::cout << "setRawBits member function called" << std::endl;
#endif

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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a <= b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a <= b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a >= b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a >= b ? a : b);
}

Fixed& Fixed::operator = (const Fixed& other)
{
#if ENABLED_FIXED_DEBUG
	std::cout << "Copy assignment operator called" << std::endl;
#endif

	if (this == &other)
		return (*this);

	Fixed tmp(other);
	this->swap(tmp);
	return (*this);
}

// MEMBER ACCESS CONTROL allows to access private member variables of different Object of the same classe
// => (other.m_rawBits)
bool Fixed::operator >  (const Fixed& other) const { return ( this->m_rawBits > other.m_rawBits ); }
bool Fixed::operator <  (const Fixed& other) const { return ( this->m_rawBits < other.m_rawBits ); }
bool Fixed::operator >= (const Fixed& other) const { return ( this->m_rawBits >= other.m_rawBits ); }
bool Fixed::operator <= (const Fixed& other) const { return ( this->m_rawBits <= other.m_rawBits ); }
bool Fixed::operator == (const Fixed& other) const { return ( this->m_rawBits == other.m_rawBits ); }
bool Fixed::operator != (const Fixed& other) const { return ( this->m_rawBits != other.m_rawBits ); }

Fixed&	Fixed::operator += (const Fixed& other)
{
	this->m_rawBits += other.m_rawBits;
	return (*this);
}

Fixed&	Fixed::operator -= (const Fixed& other)
{
	if (m_rawBits != other.m_rawBits)
		m_rawBits -= other.m_rawBits;
	else
		m_rawBits = 0;
	return (*this);
}

Fixed&	Fixed::operator *= (const Fixed& other)
{
	m_rawBits = (static_cast<int64_t>(m_rawBits) * static_cast<int64_t>(other.m_rawBits)) >> m_precision;
	return (*this);
}

Fixed&	Fixed::operator /= (const Fixed& other)
{
	m_rawBits = ((static_cast<int64_t>(m_rawBits) << m_precision) / static_cast<int64_t>(other.m_rawBits));
	return (*this);
}

Fixed	Fixed::operator + (const Fixed& other) const
{
	Fixed res(*this);
	res.m_rawBits += other.m_rawBits;
	return (res);
}

Fixed	Fixed::operator - (const Fixed& other) const
{
	Fixed res(*this);
	res.m_rawBits -= other.m_rawBits;
	return (res);
}

Fixed	Fixed::operator * (const Fixed& other) const
{
	Fixed res;
	res.m_rawBits = (static_cast<int64_t>(this->m_rawBits) * static_cast<int64_t>(other.m_rawBits)) >> other.m_precision;
	return (res);
}

Fixed	Fixed::operator / (const Fixed& other) const
{
	Fixed res;
	res.m_rawBits = ((static_cast<int64_t>(this->m_rawBits) << m_precision) / static_cast<int64_t>(other.m_rawBits));
	return (res);
}

Fixed&	Fixed::operator ++ ()
{
	this->m_rawBits += 1;
	return (*this);
}

Fixed&	Fixed::operator -- ()
{
	this->m_rawBits -= 1;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed tmp = Fixed(*this);
	++(*this);
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed tmp = Fixed(*this);
	--(*this);
	return (*this);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Fixed::swap(Fixed& other)
{
	int32_t	tmp = m_rawBits;
	m_rawBits = other.m_rawBits;
	other.m_rawBits = tmp;
}


/* ************************************************************************** */
/* ************************************************************************** */


std::ostream&  operator << (std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
