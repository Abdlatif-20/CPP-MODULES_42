/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 02:04:06 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/23 12:09:12 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanA.hpp"

void    HumanA::attack()
{
	std::cout<<name<<" attacks with their "<<weapon.getType()<<std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
	std::cout<<"HumanA created"<<std::endl;
}
