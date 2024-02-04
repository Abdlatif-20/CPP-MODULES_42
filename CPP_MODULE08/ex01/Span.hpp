/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:33:14 by aben-nei          #+#    #+#             */
/*   Updated: 2024/02/04 21:16:17 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int N;
		std::vector<int> v;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span();

		/* member functions */
		void			addNumber(int n);
		template<typename Iterator>
		void			generateNumbers(Iterator begin, Iterator end)
		{
			if (this->v.size() + std::distance(begin, end) > this->N)
				throw std::exception();
			this->v.insert(this->v.end(), begin, end);
		}

		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		unsigned int	size() const;
};