/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:15:36 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/15 16:57:55 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap("NO_NAME");
    ScavTrap scavTrap("no_name");
    
    clapTrap.attack("ABDO");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(10);
    scavTrap.attack("abdo");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();
    
    return (0);
}