/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 01:27:53 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/21 09:44:27 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *zombie;
	int	n = 2;

	zombie = zombieHorde(n, "zombie2023");
	if (zombie == NULL)
	{
		std::cout << "Error: N must be greater than 0" << std::endl;
		return (1);
	}
	for(int i = 0;i < n; i++)
	{
		zombie[i].announce();
	}
	delete [] zombie;
	return (0);
}
