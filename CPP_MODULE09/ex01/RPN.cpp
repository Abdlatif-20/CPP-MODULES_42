/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:18:01 by aben-nei          #+#    #+#             */
/*   Updated: 2024/03/12 22:22:25 by aben-nei         ###   ########.fr       */
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

void RPN::parse(std::string expr)
{
	int res = 0;
	for (size_t i = 0; i < expr.length(); i++)
	{
		if (expr[i] != '+' && expr[i] != '-' && expr[i] != '*'
			&& expr[i] != '/' && !isdigit(expr[i]) && expr[i] != ' ')
			return (std::cout << "Error" << std::endl, void());
		if (expr[i] == ' ')
			continue;
		if (isdigit(expr[i]) && _stack.size() < 2)
			_stack.push(charToInt(expr[i]));
		if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
			_expr = expr[i];
		if (_stack.size() == 2 && !_expr.empty())
		{
			int n1 = _stack.top();
			_stack.pop();
			int n2 = _stack.top();
			_stack.pop();
			if (_expr == "+")
				res = n1 + n2;
			else if (_expr == "-")
				res = n1 - n2;
			else if (_expr == "*")
				res = n1 * n2;
			else if (_expr == "/")
				res = n1 / n2;
			res < 0 ? res *= -1 : res;
			_stack.push(res);
			_expr.clear();
		}
		if (!_expr.empty() && _stack.size() != 2)
			return (std::cout << "Error" << std::endl, void());
	}
	if (_stack.size() != 1)
		return (std::cout << "Error" << std::endl, void());
	std::cout << res << std::endl;
}
