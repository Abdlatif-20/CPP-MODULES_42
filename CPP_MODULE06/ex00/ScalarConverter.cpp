/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:20:54 by aben-nei          #+#    #+#             */
/*   Updated: 2024/01/19 14:51:25 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const std::string& str) : str(str)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	if (this != &obj)
		this->str = obj.str;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

static void	checkIsInt(const std::string& str)
{
	for (int i = 0; str[i]; i++)
	{
		if (i == 0 && (str[i] == '-'  || str[i] == '+') && str.length() > 1)
			continue;
		if (!std::isdigit(str[i]))
			throw std::invalid_argument("Error: Invalid input");
	}
}

static void	checkIsFloat(const std::string& str)
{
	int repeatPoint = 0;
	for (int i = 0; str[i]; i++)
	{
		if (i == 0 && (str[i] == '-'  || str[i] == '+') && str.length() > 1)
			continue;
		if (str[i] == '.' || str[i] == 'f')
		{
			i == 0 && str[i] == 'f' ?
			throw std::invalid_argument("Error: Invalid input") : i;
			repeatPoint++;
			repeatPoint > 2 ?
			throw std::invalid_argument("Error: Invalid input") : repeatPoint;
			continue;
		}
		if (!std::isdigit(str[i]))
			throw std::invalid_argument("Error: Invalid input");
	}
}

static void	checkIsDouble(const std::string& str)
{
	int repeatPoint = 0;
	for (int i = 0; str[i]; i++)
	{
		if (i == 0 && (str[i] == '-'  || str[i] == '+') && str.length() > 1)
			continue;
		if (str[i] == '.')
		{
			repeatPoint++;
			repeatPoint > 1 ?
			throw std::invalid_argument("Error: Invalid input") : repeatPoint;
			continue;
		}
		if (!std::isdigit(str[i]) || repeatPoint > 1)
			throw std::invalid_argument("Error: Invalid input");
	}
}

static void	checkIsChar(const std::string& str)
{
	if (str.length() > 1 || !std::isprint(str[0]))
		throw std::invalid_argument("Error: Invalid input");
}

static int	checkType(const std::string& str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (CHAR);
	else if (str.find('.') != std::string::npos)
	{
		if (str.find('f') != std::string::npos)
			return (FLOAT);
		return (DOUBLE);
	}
	return (INT);
}

static void	convertToLowerCase(std::string& str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::tolower(str[i]);
}

static int	getIndex(const std::string& str)
{
	int i = 0;
	convertToLowerCase(const_cast<std::string&>(str));
	char inf[7][6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
	for (; i < 7 && str != inf[i]; i++);
	return (i);
}

static void	printInfinit(const std::string& str1, const std::string& str2)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << str1 << std::endl;
	std::cout << "double: " << str2 << std::endl;
}

static void	checkInfinit(const std::string& str)
{
	int index = getIndex(str);
	switch (index)
	{
		case 0:
		case 1:
			printInfinit("nanf", "nan");
			exit(0);
		case 2:
		case 3:
			printInfinit("+inff", "+inf");
			exit(0);
		case 4:
		case 5:
			printInfinit("-inff", "-inf");
			exit(0);
		default:
			break;
	}
}

void	ScalarConverter::convert(const std::string& str)
{
	ScalarConverter converter(str);
	checkInfinit(str);
	int type = checkType(str);
	switch (type)
	{
		case CHAR:
			checkIsChar(str);
			converter.convertChar();
			break;
		case INT:
			checkIsInt(str);
			converter.convertInt();
			break;
		case FLOAT:
			checkIsFloat(str);
			converter.convertFloat();
			break;
		case DOUBLE:
			checkIsDouble(str);
			converter.convertDouble();
			break;
		default:
			std::cout << "Error: Invalid input" << std::endl;
			break;
	}
}

static void	printTypes(char c, int i, float f, double d)
{
	i < 0 || i > 127 ?
	std::cout << "char: " << "impossible" << std::endl :
	i < 32 || i >= 127 ?
	std::cout << "char: " << "Non displayable" << std::endl :
	std::cout << "char: " << "\'"<< c << "\'" << std::endl;
	std::cout << "int: " << i << std::endl;
	f - i == 0 ?
	std::cout << "float: " << f << ".0f" << std::endl :
	std::cout << "float: " << f << "f" << std::endl;
	d - i == 0 ?
	std::cout << "double: " << d << ".0" << std::endl :
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::convertChar()
{
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	printTypes(c, i, f, d);
}

void	ScalarConverter::convertInt()
{
	long nb = std::atol(str.c_str());
	if (nb > INT_MAX || nb < INT_MIN)
		throw std::invalid_argument("Error: Invalid input");
	char	c = static_cast<char>(nb);
	float	f = static_cast<float>(nb);
	double	d = static_cast<double>(nb);
	printTypes(c, nb, f, d);
}

void	ScalarConverter::convertFloat()
{
	float	f = std::atof(str.c_str());
	int		i = static_cast<int>(f);
	char	c = static_cast<char>(f);
	double	d = static_cast<double>(f);
	printTypes(c, i, f, d);
}

void	ScalarConverter::convertDouble()
{
	double	d = std::atof(str.c_str());
	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);
	printTypes(c, i, f, d);
}
