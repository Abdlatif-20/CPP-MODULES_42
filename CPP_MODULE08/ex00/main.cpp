/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:15:21 by aben-nei          #+#    #+#             */
/*   Updated: 2024/02/07 17:59:18 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	std::list<int> l;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
	}
	std::cout << *easyfinde(v, 5) << std::endl;
	try{
		std::cout << *easyfinde(v, 15) << std::endl;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}
