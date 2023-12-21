/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:15:36 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/13 15:30:15 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("NO_NAME");
    clapTrap.attack("Abdo");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);
    return (0);
}