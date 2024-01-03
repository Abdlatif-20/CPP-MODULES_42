/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:44:38 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/23 17:22:19 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout<<"Zombie Default created"<<std::endl;
}

Zombie::Zombie(const std::string& name) : name(name)
{
	std::cout<<"Zombie parameter created"<<std::endl;
}

Zombie::~Zombie()
{
	std::cout<<"Zombie "<<getName()<<" destroyed"<<std::endl;
}

std::string	Zombie::getName()
{
	return(this->name);
}

void	Zombie::announce()
{
	std::cout<<name<<": : BraiiiiiiinnnzzzZ..."<<std::endl;
}
