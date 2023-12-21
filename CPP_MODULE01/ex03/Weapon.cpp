/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:56:48 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/12 00:39:07 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Weapon.hpp"

void    Weapon::setType(std::string type)
{
    this->type = type;
}

std::string Weapon::getType() const
{
    return (type);
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::Weapon()
{
    this->type = "default";
}