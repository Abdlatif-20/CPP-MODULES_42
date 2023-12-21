/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:15:10 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/21 14:14:44 by aben-nei         ###   ########.fr       */
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
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money.  You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

int	checkLevel(std::string level)
{
	int i = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4)
	{
		if (levels[i] == level)
			return (i);
		i++;
	}
	return (-1);
}

void Harl::complain(std::string level)
{
	int i = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	i = checkLevel(level);
	switch (i)
	{
		case 0:
				std::cout << "[ DEBUG ]" << std::endl;
				(this->*ptr[i])();
			break;
		case 1:
				std::cout << "[ INFO ]" << std::endl;
				(this->*ptr[i])();
			break;
		case 2:
				std::cout << "[ WARNING ]" << std::endl;
				(this->*ptr[i])();
			break;
		case 3:
				std::cout << "[ ERROR ]" << std::endl;
				(this->*ptr[i])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}