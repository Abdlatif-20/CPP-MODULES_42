/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:50:53 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/20 21:41:30 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>

template<typename T>
Array<T>::Array()
{
	this->size = 0;
	this->array = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->size = n;
	this->array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->array[i] = 0;
}

template<typename T>
Array<T>::Array(Array const &rhs)
{
	this->size = rhs.size;
	this->array = new T[rhs.size];
	for (unsigned int i = 0; i < rhs.size; i++)
		this->array[i] = rhs.array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		if (this->array)
			delete[] this->array;
		this->size = rhs.size;
		this->array = new T[rhs.size];
		for (unsigned int i = 0; i < rhs.size; i++)
			this->array[i] = rhs.array[i];
	}
	return (*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->size)
		throw std::exception();
	return (this->array[i]);
}

template<typename T>
unsigned int Array<T>::getSize() const
{
	return(this->size);
}

template<typename T>
Array<T>::~Array()
{
	if (this->array)
		delete[] this->array;
}
