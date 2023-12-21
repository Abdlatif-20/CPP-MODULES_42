/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:15:36 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/15 17:12:25 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("clap");
    ScavTrap scav("scav");
    FragTrap frag("frag");
    
    clap.attack("clapAttack");
    clap.takeDamage(10);
    clap.beRepaired(10);
    std::cout << std::endl;
    scav.attack("scavAttack");
    scav.takeDamage(10);
    scav.beRepaired(10);
    scav.guardGate();
    std::cout << std::endl;
    frag.attack("fragAttack");
    frag.takeDamage(10);
    frag.beRepaired(10);
    frag.highFivesGuys();
    return (0);
}