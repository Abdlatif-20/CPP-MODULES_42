/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:51:13 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/02 18:24:07 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include<cmath>

class Fixed
{
	private:
		int				fixedPoint;
		static const int bits;
	public:
		Fixed();
		Fixed(const int fixePoint);
		Fixed(const float value);
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);