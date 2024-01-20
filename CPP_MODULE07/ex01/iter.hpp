/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:38:15 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/20 18:46:01 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T, typename T1, typename F>

void	iter(T*	arr, T1 len, F func)
{
	for (int i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}