/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:45:18 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/05 11:23:35 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " is born!" << std::endl;
	this->name = "default";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->name << " is born!" << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "ScavTrap operator=" << std::endl;
	ClapTrap::operator=(obj);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " is dead!" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
	if (this->energyPoint <= 0 || this->hitPoint <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attack " << target << ", causing "
		<< this->attackDamage << " points of damage!" << std::endl;
	this->energyPoint--;
}

void ScavTrap::guardGate()
{
	if (this->hitPoint > 0 && this->energyPoint > 0)
		std::cout << "ScavTrap " << this->name << " has enterred in Gate keeper mode" << std::endl;
}