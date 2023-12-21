/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:06:13 by aben-nei          #+#    #+#             */
/*   Updated: 2023/12/10 21:56:55 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int	main(int ac, char **av)
{
	char		**string_av;
	std::string string;
	if (ac == 1)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return (0);
	}
	string_av = av + 1;
	for(int i = 0;string_av[i];i++)
	{
		string = string_av[i];
		for(int j = 0;string[j];j++)
		{
			std::cout<<(char)toupper(string[j]);
		}
	}
	std::cout<<std::endl;
	return (0);
}