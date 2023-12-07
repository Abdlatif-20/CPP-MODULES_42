/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:15:10 by aben-nei          #+#    #+#             */
/*   Updated: 2023/11/05 19:53:52 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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

void Harl::complain(std::string level)
{
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (i <= 4)
    {
        switch (i)
        {
        case 0:
            if (levels[i] == level)
            {
                std::cout << "[ DEBUG ]"<< std::endl;
                (this->*ptr[i])();
                return;
            }
            break;
        case 1:
            if (levels[i] == level)
            {
                std::cout << "[ INFO ]"<< std::endl;
                (this->*ptr[i])();
                return;
            }
            break;
        case 2:
            if (levels[i] == level)
            {
                std::cout << "[ WARNING ]"<< std::endl;
                (this->*ptr[i])();
                return;
            }
            break;
        case 3:
            if (levels[i] == level)
            {
                std::cout << "[ ERROR ]"<< std::endl;
                (this->*ptr[i])();
                return;
            }
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
        }
        i++;
    }
}