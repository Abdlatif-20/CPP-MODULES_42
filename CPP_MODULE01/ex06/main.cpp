/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:21:50 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/24 22:02:02 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter [\"DEBUG\"/\"INFO\"/\"WARNING\"/\"ERROR\"]" << std::endl;
		return (1);
	}
	Harl    harl;

	harl.complain(av[1]);
	return (0);
}