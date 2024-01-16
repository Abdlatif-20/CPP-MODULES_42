/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:40:33 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/05 13:12:04 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d("Abdo");
	d.attack("morocco");
	d.takeDamage(10);
	d.beRepaired(10);
	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();
	return 0;
}