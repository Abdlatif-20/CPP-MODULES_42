/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:56:37 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/15 17:08:49 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " is created" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " is destroyed" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << getName() << " attack " << target << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " have enterred in Gate keeper mode" << std::endl;
}