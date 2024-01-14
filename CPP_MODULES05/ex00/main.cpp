/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:43:39 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/14 20:02:51 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

int main()
{
	Bureaucrat bureau("name", 150);
	bureau.decrementGrade();
	std::cout<<bureau<<std::endl;
	return (0);
}
