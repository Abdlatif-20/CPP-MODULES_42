/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:14:27 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/16 16:29:24 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->name = name;
    
    std::cout << "DiamondTrap " << this->name << " is born" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " is dead" << std::endl;
}

std::string	DiamondTrap::getName()
{
    return (this->name);
}

void	DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}