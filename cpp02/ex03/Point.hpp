/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:13:59 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/17 19:46:51 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const Point& other);
	Point(const float fx, const float fy);
	~Point();

	Point&	operator = (const Point& other);
	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;

private:
	const Fixed	m_x;
	const Fixed	m_y;
};

std::ostream& operator << (std::ostream& os, const Point& point);

#endif
