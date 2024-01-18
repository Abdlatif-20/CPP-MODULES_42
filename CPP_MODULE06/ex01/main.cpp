/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:44:31 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/18 17:09:45 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Serialize.hpp"

#include <iostream>
struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

struct Data2
{
	std::string s1;
	int n;
	std::string s2;
};

int main()
{
	Data *data = new Data;
	Data2 *data2;

	data2 = (Data2 *)data;
	std::cout << "data2: " << &data2 << std::endl;
	std::cout << "data: " << &data << std::endl;
	std::cout << "data2->s1: " << data2->s1 << std::endl;
	std::cout << "data2->n: " << data2->n << std::endl;
	// Using reinterpret_cast to convert a pointer to a uintptr_t
	// std::cout<<"sizeof uintptr_t: "<<sizeof(uintptr_t)<<std::endl;
	// std::cout<<"sizeof void*: "<<sizeof(void*)<<std::endl;
	// std::cout<<"sizeof Data: "<<sizeof(data)<<std::endl;
	// uintptr_t intValueAsInt = reinterpret_cast<uintptr_t>(&data);
	// void* voidPtr = &data;

	// std::cout << "The value of intPtr is: " << &data << std::endl;
	// std::cout << "The value of voidPtr is: " << &intValueAsInt << std::endl;
	return (0);
}