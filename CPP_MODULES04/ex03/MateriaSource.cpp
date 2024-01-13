/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:35:00 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/13 10:54:57 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		if (obj.inventory[i] != NULL)
			this->inventory[i] = obj.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == m)
			return ;
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
	delete m;
}
AMateria*  MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL && this->inventory[i]->getType() == type)
			return (this->inventory[i]->clone());
	}
	return (NULL);
}
