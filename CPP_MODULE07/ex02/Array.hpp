/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:49:08 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/23 01:12:20 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>

template<typename T>
class Array
{
	private:
		T *array;
		unsigned int size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &rhs);
		Array &operator=(Array const &rhs);
		T &operator[](unsigned int i);
		const T &operator[](unsigned int i) const;
		unsigned int getSize() const;
		~Array();
};

#include "Array.tpp"