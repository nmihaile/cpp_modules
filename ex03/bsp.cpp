/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:55:41 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/17 19:35:43 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

static Fixed	edgeFunc(const Point& a, const Point& b, const Point& p)
{
	return ((b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed ab;
	Fixed bc;
	Fixed ca;

	ab = edgeFunc(a, b, point);
	bc = edgeFunc(b, c, point);
	ca = edgeFunc(c, a, point);

	if ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0))
		return (true);
	return (false);
}


// (a: Point, b: Point, c: Point, p: Point)
// (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x)
// (c.x - b.x) * (p.y - b.y) - (c.y - b.y) * (p.x - b.x)
// (a.x - b.x) * (p.y - b.y) - (a.y - b.y) * (p.x - b.x)
