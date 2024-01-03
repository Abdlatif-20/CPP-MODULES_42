/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:09:26 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/02 18:50:59 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	this->fixedPoint = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int fixedPoint)
{
	this->fixedPoint = fixedPoint * (1 << this->bits);
	std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(const float value)
{
	this->fixedPoint = std::roundf(value * pow(2, this->bits));
	std::cout<<"float constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	*this = obj;
	std::cout<<"Copy constructor called"<<std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called"<<std::endl;
}
int Fixed::getRawBits( void ) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return(this->fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
	this->fixedPoint = raw;
	std::cout<<"setRawBits member function called"<<std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	this->fixedPoint = obj.fixedPoint;
	std::cout<<"Copy assignment operator called"<<std::endl;
	return(*this);
}

int		Fixed::toInt( void ) const
{
	return(this->fixedPoint >> this->bits);
}

float	Fixed::toFloat( void ) const
{
	return((float)this->fixedPoint / (1 << this->bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return(os);
}
