/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:51:13 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/02 18:50:00 by aben-nei         ###   ########.fr       */
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
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		/*Comparison operators*/
		bool	operator>(const Fixed& obj) const;
		bool	operator<(const Fixed& obj) const;
		bool	operator>=(const Fixed& obj) const;
		bool	operator<=(const Fixed& obj) const;
		bool	operator==(const Fixed& obj) const;
		bool	operator!=(const Fixed& obj) const;
		
		/*Arithmetic operators*/
		Fixed	operator*(const Fixed& obj) const;
		Fixed	operator+(const Fixed& obj) const;
		Fixed	operator-(const Fixed& obj) const;
		Fixed	operator/(const Fixed& obj) const;

		/*Increment and decrement operators*/
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		static Fixed&	max(const Fixed& a, const Fixed& b);
		static Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static Fixed&	min(Fixed& a, Fixed& b);

};
std::ostream& operator<<(std::ostream& os, const Fixed& obj);