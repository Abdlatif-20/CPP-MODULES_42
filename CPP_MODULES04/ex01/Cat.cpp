/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:21:12 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/13 11:18:13 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
}
Cat::Cat(const Cat& obj) : Animal(obj)
{
	this->brain = new Brain(*obj.brain);
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this == &obj)
		return *this;
	Animal::operator=(obj);
	delete this->brain;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Miaw Miaw" << std::endl;
}