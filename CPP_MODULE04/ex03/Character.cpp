/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:24:49 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/13 10:52:44 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->name = "default";
}

Character::Character(std::string name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->name = name;
}

Character::Character(const Character& obj)
{
	/*Because copy constructor depends on copy assignment I should initialize the inventory by NULL*/
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = obj;
}

Character& Character::operator=(const Character& obj)
{
	/*deep copy here !!!*/
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			if (obj.inventory[i] != NULL)
				this->inventory[i] = obj.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
		this->name = obj.name;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

const std::string& Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4 && m != this->inventory[i]; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		return ;
	this->inventory[idx]->use(target);
}