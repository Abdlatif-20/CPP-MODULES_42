/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:48:59 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/23 01:59:31 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> intArray;
	Array<int> intArray4(5);
	Array<char> charArray(5);
	Array<std::string> stringArray(5);

	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";
	std::cout << stringArray[0] << " " << stringArray[1] << " " << stringArray[2] << std::endl;
	std::cout << stringArray.getSize() << std::endl;
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