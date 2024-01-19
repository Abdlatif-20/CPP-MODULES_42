/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:44:31 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/19 15:53:17 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
	Data* data = new Data;
	data->s1 = "Hello";
	data->n = 42;
	data->s2 = "World";

	uintptr_t raw = Serialize::serialize(data);
	Data* data2 = Serialize::deserialize(raw);

	std::cout << "--------- Data2 ------------" << std::endl;
	std::cout << data2->s1 << std::endl;
	std::cout << data2->n << std::endl;
	std::cout << data2->s2 << std::endl;
	std::cout << "----------- Data ----------" << std::endl;
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
	std::cout << "----------- raw ----------" << std::endl;
	std::cout << raw << std::endl;
	std::cout << "---------- Data Addr -----------" << std::endl;
	std::cout << data << std::endl;
	std::cout << data2 << std::endl;
	std::cout << "---------------------" << std::endl;
	delete data;
	return (0);
}