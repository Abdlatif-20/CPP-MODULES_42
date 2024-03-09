/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:08:01 by aben-nei          #+#    #+#             */
/*   Updated: 2024/03/09 12:00:45 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <vector>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
		public:
			MutantStack();
			MutantStack(MutantStack const &rhs);
			MutantStack &operator=(MutantStack const &rhs);
			~MutantStack();
			typedef typename std::stack<T, Container>::container_type::iterator iterator;
			iterator begin();
			iterator end();
};

#include "MutantStack.tpp"