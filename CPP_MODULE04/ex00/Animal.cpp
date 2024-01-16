/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:06:50 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/13 11:14:39 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "animal";
}
Animal::Animal(const Animal& obj)
{
	*this = obj;
}
Animal& Animal::operator=(const Animal& obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

Animal::~Animal()
{
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::setType(std::string type)
{
	this->type = type;
}