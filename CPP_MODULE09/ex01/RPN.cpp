/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:18:01 by aben-nei          #+#    #+#             */
/*   Updated: 2024/03/20 17:14:56 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	_expr.clear();
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_expr = other._expr;
		_stack = other._stack;
	}
	return *this;
}

static int charToInt(char c)
{
	return c - '0';
}

void RPN::rpn(std::string expr)
{
	int res = 0;
	for (size_t i = 0; i < expr.length(); i++)
	{
		if (expr.find_first_not_of("0123456789+-*/ ") != std::string::npos)
			return (std::cout << "Error" << std::endl, void());
		if (expr[i] == ' ')
			continue;
		if (isdigit(expr[i]))
			_stack.push(charToInt(expr[i]));
		if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
			_expr = expr[i];
		if (_stack.size() > 1 && !_expr.empty())
		{
			int n1 = _stack.top();
			_stack.pop();
			int n2 = _stack.top();
			_stack.pop();
			if (_expr == "*")
				res = n2 * n1;
			else if (_expr == "+")
				res = n2 + n1;
			else if (_expr == "-")
				res = n2 - n1;
			else if (_expr == "/")
			{
				if (n1 == 0)
					return (std::cout << "cant devide by 0" << std::endl, void());
				res = n2 / n1;
			}
			_stack.push(res);
			_expr.clear();
		}
		else if (_stack.size() == 1 && !_expr.empty())
			return (std::cout << "Error" << std::endl, void());
	}
	if (_stack.size() != 1)
		return (std::cout << "Error" << std::endl, void());
	res = _stack.top();
	std::cout << res << std::endl;
}
