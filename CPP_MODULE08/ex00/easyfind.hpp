/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:20:26 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/23 04:06:18 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int a);
template<typename T>
typename T::iterator easyfinde(T& container, int a);

#include "easyfind.tpp"