/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:43:39 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/15 21:47:52 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 2);
		Bureaucrat b2("b2", 149);
		Form f1("f1", 1, 1);
		Form f2("f2", 149, 149);
		Form f3("f3", 75, 75);
		Form f4("f4", 150, 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
		std::cout << f4 << std::endl;

		b1.incrementGrade();
		b2.decrementGrade();
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		b1.signForm(f1);
		b1.signForm(f2);
		b1.signForm(f3);
		b1.signForm(f4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
