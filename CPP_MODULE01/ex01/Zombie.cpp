/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:21:48 by aben-nei          #+#    #+#             */
/*   Updated: 2023/10/18 01:21:56 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::setName(std::string name)
{
	this->string_name = name;
}
std::string	Zombie::getNmae()
{
	return(this->string_name);	
}

Zombie::~Zombie()
{
	std::cout<<"Zombie <"<<getNmae()<<"> destroyed"<<std::endl;
}

void	Zombie::announce()
{
	std::cout<<string_name<<": : BraiiiiiiinnnzzzZ..."<<std::endl;
}