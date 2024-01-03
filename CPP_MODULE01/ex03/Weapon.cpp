/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:56:48 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/23 17:47:06 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Weapon.hpp"

void	Weapon::setType(const std::string& type)
{
	this->type = type;
}

const std::string&	Weapon::getType() const
{
	return (type);
}

Weapon::Weapon(const std::string& type) : type(type)
{
	std::cout<<"Weapon created"<<std::endl;
}

Weapon::Weapon()
{
	this->type = "default";
}
