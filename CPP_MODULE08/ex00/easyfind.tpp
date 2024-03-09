/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:33:27 by aben-nei          #+#    #+#             */
/*   Updated: 2024/03/03 23:59:40 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
typename T::iterator easyfinde(T& container, int a)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), a);
	if (it != container.end())
		return it;
	throw std::exception();
}
