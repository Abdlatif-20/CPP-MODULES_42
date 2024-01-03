/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 02:45:22 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/03 11:46:37 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0, 1);
	Point b(0, 5);
	Point c(5, 0);
	Point point(0, 4.99);
	std::cout << point.getY() << std::endl;
	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}
