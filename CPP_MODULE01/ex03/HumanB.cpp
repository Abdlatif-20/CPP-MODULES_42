/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 02:09:00 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/21 10:26:52 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanB.hpp"

void    HumanB::attack()
{
    std::cout<<name<<" attacks with their "<<weapon.getType()<<std::endl;
}

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::HumanB()
{
    this->name = "default";
}

void    HumanB::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}

