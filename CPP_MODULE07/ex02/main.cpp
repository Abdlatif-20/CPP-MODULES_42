/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:48:59 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/21 00:19:24 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// void	ff()
// {
// 	system("leaks array");
// }

int main()
{
	// atexit(ff);
	Array<int> intArray;
	Array<int> intArray1(5);
	Array<int> intArray4(5);

	std::cout << intArray4.getSize() << std::endl;
	intArray4[0] = 42;
	std::cout << intArray4[0] << std::endl;
	try
	{
		std::cout << intArray4[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}