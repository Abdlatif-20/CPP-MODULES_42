/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:09:26 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/02 19:55:58 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixedPoint = 0;
	// std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int fixedPoint)
{
	this->fixedPoint = fixedPoint * (1 << this->bits);
	// std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(const float value)
{
	this->fixedPoint = std::roundf(value * (1 << this->bits));
	// std::cout<<"float constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	*this = obj;
	// std::cout<<"Copy constructor called"<<std::endl;
}
Fixed::~Fixed()
{
	// std::cout<<"Destructor called"<<std::endl;
}
int Fixed::getRawBits( void ) const
{
	// std::cout<<"getRawBits member function called"<<std::endl;
	return(this->fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	this->fixedPoint = raw;
	// std::cout<<"setRawBits member function called"<<std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	this->fixedPoint = obj.fixedPoint;
	// std::cout<<"Copy assignment operator called"<<std::endl;
	return(*this);
}

float	Fixed::toFloat( void ) const
{
	return((float)this->fixedPoint / (1 << this->bits));
}

int		Fixed::toInt( void ) const
{
	return(this->fixedPoint * (1 >> this->bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return(os);
}

bool	Fixed::operator>(const Fixed& obj) const
{
	return(this->fixedPoint > obj.fixedPoint);
}

bool	Fixed::operator<(const Fixed& obj) const
{
	return(this->fixedPoint < obj.fixedPoint);
}

bool	Fixed::operator>=(const Fixed& obj) const
{
	return(this->fixedPoint >= obj.fixedPoint);
}

bool	Fixed::operator<=(const Fixed& obj) const
{
	return(this->fixedPoint <= obj.fixedPoint);
}

bool	Fixed::operator!=(const Fixed& obj) const
{
	return(this->fixedPoint != obj.fixedPoint);
}

Fixed	Fixed::operator*(const Fixed& obj) const
{
	return(this->toFloat() * obj.toFloat());
}

Fixed	Fixed::operator+(const Fixed& obj) const
{
	return(this->toFloat() + obj.toFloat());
}

Fixed	Fixed::operator-(const Fixed& obj) const
{
	return(this->toFloat() - obj.toFloat());
}

Fixed	Fixed::operator/(const Fixed& obj) const
{
	if (obj.toFloat() == 0)
	{
		std::cout << "Division by zero is not allowed" << std::endl;
		exit(1);
	}
	return(this->toFloat() / obj.toFloat());
}

Fixed	Fixed::operator++()
{
	++fixedPoint;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed copy(*this);
	++fixedPoint;
	return(copy);
}

Fixed	Fixed::operator--()//prefix decrement
{
	--fixedPoint;
	return(*this);
}

Fixed	Fixed::operator--(int)//postfix decrement
{
	Fixed copy(*this);
	--fixedPoint;
	return(copy);
}

Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return((Fixed&)a);
	return((Fixed&)b);
}

Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return((Fixed&)a);
	return((Fixed&)b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return(a);
	return(b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return(a);
	return(b);
}
bool	Fixed::operator==(const Fixed& obj) const
{
	return(this->fixedPoint == obj.fixedPoint);
}