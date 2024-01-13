/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:04:11 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/13 11:28:35 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string type;
		// hidden pointer vptr to virtual table
	public:
		Animal();
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		virtual ~Animal(); // virtual add

		virtual void makeSound() const = 0; // pure virtual function

		std::string getType() const;
		void setType(std::string type);
};