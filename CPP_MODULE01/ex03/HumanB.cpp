/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 02:09:00 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/23 22:27:48 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanB.hpp"

void    HumanB::attack()
{
	if (this->weapon)
		std::cout<<name<<" attacks with their "<<weapon->getType()<<std::endl;
	else
		std::cout<<name<<" attacks with their bare hands"<<std::endl;
}

HumanB::HumanB(std::string name)
{
	this->weapon = NULL;
	this->name = name;
}

HumanB::HumanB()
{
	this->name = "default";
}

void    HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

