/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:31:03 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/17 21:39:02 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

class Serialize
{
	private:
	/************** canonical form **************/
	
		Serialize();
		Serialize(const Serialize& obj);
		Serialize& operator=(const Serialize& obj);
		~Serialize();
	public:
	/************** member functions **************/
	
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
