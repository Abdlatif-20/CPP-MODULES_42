/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:21:59 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/02 20:08:34 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed checkArea(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
	Fixed areaResult = ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
	if (areaResult < 0)
		areaResult = areaResult * -1;
	return areaResult;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = checkArea(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed areaPBC = checkArea(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed areaAPC = checkArea(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
	Fixed areaABP = checkArea(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());
	if ((areaPBC + areaAPC + areaABP) == areaABC && areaPBC != 0 && areaAPC != 0 && areaABP != 0)
		return (true);
	return (false);
}
