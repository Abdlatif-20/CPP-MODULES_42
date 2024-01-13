/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:18:45 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/13 11:33:37 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	this->brain = new Brain(*obj.brain);
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this == &obj)
		return *this;
	Animal::operator=(obj);
	delete this->brain;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}