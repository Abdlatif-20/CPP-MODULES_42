/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:09:26 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/02 18:23:13 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	this->fixedPoint = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = obj;
}
Fixed& Fixed::operator=(const Fixed& obj)
{
	this->fixedPoint = obj.fixedPoint;
	std::cout<<"Copy assignment operator called"<<std::endl;
	return(*this);
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
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
