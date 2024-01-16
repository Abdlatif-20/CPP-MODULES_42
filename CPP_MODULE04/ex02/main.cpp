/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:34:19 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/13 11:35:08 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void func()
{
	system("leaks Animal");
}

int main()
{
	Animal *animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
			std::cout << "---------------------" << std::endl;
		animals[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
		delete animals[i];
	return (0);
}