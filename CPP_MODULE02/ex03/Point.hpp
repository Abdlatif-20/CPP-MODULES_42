/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:16:42 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/03 11:16:03 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& obj);
		Point& operator=(const Point& obj);
		const Fixed&	getX() const;
		const Fixed&	getY() const;
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);