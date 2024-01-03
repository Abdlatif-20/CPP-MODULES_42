/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:18:32 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/02 19:19:44 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point& obj) : x(obj.x), y(obj.y)
{
}

Point::~Point()
{
}

Point& Point::operator=(const Point& obj)
{
	(void)obj;
	return (*this);
}

const Fixed&	Point::getX() const
{
	return (this->x);
}

const Fixed&	Point::getY() const
{
	return (this->y);
}