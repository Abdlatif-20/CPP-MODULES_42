/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:13:29 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/17 18:14:04 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
	private:
		std::string str;

		/************ canonical form **************/

		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();
		ScalarConverter(const std::string& str);

		/*********** methods Private **************/

		void	convertChar();
		void	convertInt();
		void	convertFloat();
		void	convertDouble();
	public:
		/*********** methods Public ***************/

		static void convert(const std::string& str);
};