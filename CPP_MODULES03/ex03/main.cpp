/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:15:36 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/16 16:32:37 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("ABDO");
    diamond.attack("NO_NAME");
    diamond.takeDamage(10);
    diamond.beRepaired(10);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
}