/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:28:25 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/27 06:11:23 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./bitcoin [file]" << std::endl;
		return 1;
	}
	try{
		BitcoinExchange::btcExchange(av[1], "BTC");
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	return 0;
}
