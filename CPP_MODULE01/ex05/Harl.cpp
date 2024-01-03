/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:15:10 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/23 18:53:34 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	ptr[0] = &Harl::debug;
	ptr[1] = &Harl::info;
	ptr[2] = &Harl::warning;
	ptr[3] = &Harl::error;
}

void Harl::debug()
{
    std::cout << "love having extra bacon for my \
 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon cost more money.\
 You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free.\
 I've been coming here for years and you just started working here last month.\n" << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int j = 0; j < 4; j++)
	{
		if (levels[j] == level)
		{
			std::cout << "[ " << level << " ]" << std::endl;
			(this->*ptr[j])();
			return ;
		}
	}
}
