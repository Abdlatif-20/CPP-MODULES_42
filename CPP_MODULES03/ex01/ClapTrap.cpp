/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:45:46 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/15 17:08:31 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << name << " is created" << std::endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	this->name = name;
}

ClapTrap ::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " is destroyed" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->name << " attack " << target << std::endl;
	this->energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " take " << amount << " damage" << std::endl;
	this->hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " be repaired " << amount << std::endl;
	this->hitPoints += amount;	
}

int		ClapTrap::getHitPoints()
{
	return (this->hitPoints);
}

void	ClapTrap::setHitPoints(int hitPoints)
{
	this->hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int energyPoints)
{
	this->energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int attackDamage)
{
	this->attackDamage = attackDamage;
}

std::string	ClapTrap::getName()
{
	return (this->name);
}

int	ClapTrap::getEnergyPoints()
{
	return (this->energyPoints);
}

int	ClapTrap::getAttackDamage()
{
	return (this->attackDamage);
}