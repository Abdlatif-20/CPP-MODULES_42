/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:33:50 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/13 11:20:42 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	(void)obj;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
}

void WrongAnimal::makeSound() const
{
}