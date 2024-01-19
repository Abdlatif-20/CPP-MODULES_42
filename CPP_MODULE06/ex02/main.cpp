/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:16:44 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/19 17:28:23 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base *base = new Base;
	Base *a = new A;
	Base *b = new B;
	Base *c = new C;

	Base *random = generate();

	std::cout << "identify : " << std::endl;
	identify(base);
	identify(a);
	identify(b);
	identify(c);
	std::cout << "identify(Base* p) : " << std::endl;
	identify(random);
	std::cout << "identify(Base& p) : " << std::endl;
	identify(*random);


	delete base;
	delete a;
	delete b;
	delete c;
	delete random;
	return (0);
}
