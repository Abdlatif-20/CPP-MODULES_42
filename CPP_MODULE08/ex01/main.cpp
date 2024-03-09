/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:32:52 by aben-nei          #+#    #+#             */
/*   Updated: 2024/03/09 13:28:48 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		{
			Span sp = Span(5);
			for (unsigned int i = 0; i < sp.size(); i++)
				sp.addNumber(i);
			std::cout << "-->shortestSpan: " << sp.shortestSpan() << std::endl;
			std::cout << "-->longestSpan: " << sp.longestSpan() << std::endl;
		}
		std::cout << "-------------------" << std::endl;
		{
			Span sp(10000);
			srand(time(NULL));
			std::vector<int> v(10000);
			std::generate(v.begin(), v.end(), rand);
			sp.generateNumbers(v.begin(), v.end());
			std::cout << "->shortestSpan: " << sp.shortestSpan() << std::endl;
			std::cout << "->longestSpan: " << sp.longestSpan() << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}