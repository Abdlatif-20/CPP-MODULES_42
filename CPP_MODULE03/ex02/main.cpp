/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:40:33 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/08 21:12:56 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap fragTrap("Abdo");
	fragTrap.attack("morocco");
	fragTrap.takeDamage(20);
	fragTrap.beRepaired(10);
	fragTrap.highFivesGuys();
	return 0;
}