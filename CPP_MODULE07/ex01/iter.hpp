/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:38:15 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/21 22:32:03 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T, typename F>
void	iter(T*	arr, size_t len, F func)
{
	if (!arr || !func)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

template<typename T>
void	printType(T i)
{
	std::cout << i << std::endl;
}