/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:21:12 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/13 11:04:30 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
}
Cat::Cat(const Cat& obj) : Animal(obj)
{
}

Cat& Cat::operator=(const Cat& obj)
{
	Animal::operator=(obj);
	return (*this);
}

Cat::~Cat()
{
}

void Cat::makeSound() const
{
	std::cout << "Miaw Miaw" << std::endl;
}