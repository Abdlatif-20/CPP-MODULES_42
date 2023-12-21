/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:27:53 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/08 23:15:41 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *zombie;

	zombie = zombieHorde(5, "zombie2023");
	for(int i = 0;i < 5; i++)
	{
		zombie[i].announce();
	}
	delete [] zombie;
	return (0);
}
