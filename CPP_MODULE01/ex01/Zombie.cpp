/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:21:48 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/23 15:53:26 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::setName(std::string name)
{
	this->name = name;
}
std::string	Zombie::getName()
{
	return(this->name);	
}

Zombie::Zombie()
{
	std::cout<<"Zombie created"<<std::endl;
}

Zombie::~Zombie()
{
	std::cout<<"Zombie "<<getName()<<" destroyed"<<std::endl;
}

void	Zombie::announce()
{
	std::cout<<name<<": : BraiiiiiiinnnzzzZ..."<<std::endl;
}