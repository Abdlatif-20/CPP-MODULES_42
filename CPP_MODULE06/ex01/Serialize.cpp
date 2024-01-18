/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:34:02 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/17 21:41:20 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize()
{
}

Serialize::Serialize(const Serialize& obj)
{
	*this = obj;
}

Serialize& Serialize::operator=(const Serialize& obj)
{
	(void)obj;
	return (*this);
}

Serialize::~Serialize()
{
}

uintptr_t	Serialize::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}