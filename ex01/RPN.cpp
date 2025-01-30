/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:13:43 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/29 17:43:20 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


long long	RPN::evaluate(std::string expression)
{
	std::stringstream	ss(expression);

	while (42)
	{
		char	c;
		ss >> c;

		if (ss.eof())
			break ;
		if (ss.fail())
			throw ( std::runtime_error("Error") );

		if (isOperator(c))
		{
			switch (c)
			{
				case '*':
					m_stack.push(mul());
					break ;
				case '+':
					m_stack.push(add());
					break ;
				case '-':
					m_stack.push(sub());
					break ;
				case '/':
					m_stack.push(div());
					break ;
			}
		}
		else if (std::isdigit(c))
			m_stack.emplace(c - 48);
		else
			throw ( std::runtime_error(std::string("Error: invalid character: '") + c + '\'') );
	}

	if (m_stack.size() > 1)
		throw ( std::runtime_error(std::string("Error: to many values in stack left")) );
	else if (m_stack.size() < 1)
		throw ( std::runtime_error(std::string("Error: no result stored in stack")) );

	long long	result = m_stack.top();
	m_stack.pop();

	return (result);
}


/* ************************************************************************** */
/* ************************************************************************** */


bool	RPN::isOperator(char c)
{
	return (c == '*' || c == '+' || c == '-' || c == '/');
}

long long	RPN::mul(void)
{
	if (m_stack.size() < 2)
		throw( std::runtime_error("Error: Not enougth operands for multiplication") );

	long long b = m_stack.top();
	m_stack.pop();
	long long a = m_stack.top();
	m_stack.pop();

	return (a * b);
}

long long	RPN::add(void)
{
	if (m_stack.size() < 2)
		throw( std::runtime_error("Error: Not enougth operands for addition") );

	long long b = m_stack.top();
	m_stack.pop();
	long long a = m_stack.top();
	m_stack.pop();

	return (a + b);
}

long long	RPN::sub(void)
{
	if (m_stack.size() < 2)
		throw( std::runtime_error("Error: Not enougth operands for subtraction") );

	long long b = m_stack.top();
		m_stack.pop();
	long long a = m_stack.top();
		m_stack.pop();

	return (a - b);
}

long long	RPN::div(void)
{
	if (m_stack.size() < 2)
		throw( std::runtime_error("Error: Not enougth operands for division") );

	long long b = m_stack.top();
		m_stack.pop();
	if (b == 0)
		throw ( std::runtime_error("Error: division by 0") );

	long long a = m_stack.top();
		m_stack.pop();

	return (a / b);
}

