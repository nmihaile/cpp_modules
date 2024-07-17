/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:13:58 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/17 19:52:16 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : m_x(0), m_y(0)
{
}

Point::Point(const Point& other) : m_x(other.m_x), m_y(other.m_y)
{
}

Point::Point(const float fx, const float fy) : m_x(fx), m_y(fy)
{
}

Point::~Point()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


Point&	Point::operator = (const Point& other)
{
	static_cast<void>(other);
	return (*this);
}
// This could be used to assigne a new point. But there is no point to assign
// a new point to the CONST m_x and m_y, because they are CONST!!!
//
// if (this != &other)
// {
// 	*const_cast<Fixed*>(&m_x) = other.m_x;
// 	*const_cast<Fixed*>(&m_y) = other.m_y;
// }

const Fixed&	Point::getX(void) const
{
	return (m_x);
}

const Fixed&	Point::getY(void) const
{
	return (m_y);
}


/* ************************************************************************** */
/* ************************************************************************** */


std::ostream& operator << (std::ostream& os, const Point& point)
{
	// std::ostream os;
	os << "Point(" << point.getX() << ", " << point.getY() << ")";
	return (os);
}
