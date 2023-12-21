/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:27:53 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/12 00:59:18 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
    Zombie *zombie;

    zombie = zombieHorde(3, "zombie2023");
    if (zombie == NULL)
    {
        std::cout << "Error: N is negative or null" << std::endl;
        return (1);
    }
    for(int i = 0;i < 3; i++)
    {
        zombie[i].announce();
    }
    delete [] zombie;
    return (0);
}