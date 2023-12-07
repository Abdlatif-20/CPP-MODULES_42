/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:44:38 by aben-nei          #+#    #+#             */
/*   Updated: 2023/11/11 17:56:48 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout<<"Zombie created"<<std::endl;
}

Zombie::~Zombie()
{
	std::cout<<"Zombie <"<<getNmae()<<"> destroyed"<<std::endl;
}

void	Zombie::setName(std::string name)
{
	this->string_name = name;
}
std::string	Zombie::getNmae()
{
	return(this->string_name);	
}

void	Zombie::announce()
{
	std::cout<<string_name<<": : BraiiiiiiinnnzzzZ..."<<std::endl;
}