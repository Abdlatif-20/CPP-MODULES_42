/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:18:45 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/13 11:04:43 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
}

Dog& Dog::operator=(const Dog& obj)
{
	Animal::operator=(obj);
	return (*this);
}

Dog::~Dog()
{
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}