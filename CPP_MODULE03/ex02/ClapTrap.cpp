/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:40:29 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/08 16:51:11 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "ClapTrap copy" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "ClapTrap operator=" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoint = obj.hitPoint;
		this->energyPoint = obj.energyPoint;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoint <= 0 || this->hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attack " << target << ", causing "
		<< this->attackDamage << " points of damage!" << std::endl;
	this->energyPoint--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " take " << amount
		<< " points of damage!" << std::endl;
	this->hitPoint -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint <= 0 || this->energyPoint <= 0)
		return;
	std::cout << "ClapTrap " << this->name << " be repaired "
		<< amount << " points of damage!" << std::endl;
	this->hitPoint += amount;
	this->energyPoint--;
}
