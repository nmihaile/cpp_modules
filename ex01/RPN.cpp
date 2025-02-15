/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:13:43 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/31 14:11:35 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }

RPN::~RPN() { }


/* ************************************************************************** */
/* ************************************************************************** */


long long	RPN::evaluate(const std::string expression)
{
	std::stringstream	ss(expression);
	char				c;

	while (ss >> c)
	{
		if (ss.eof())
			break ;
		if (ss.fail())
			throw ( std::runtime_error("Error") );

		switch (c)
		{
			case '*': mul(); break ;
			case '+': add(); break ;
			case '-': sub(); break ;
			case '/': div(); break ;
			default:
				if (std::isdigit(c))
					m_stack.emplace(c - 48);
				else
					throw ( std::runtime_error(std::string("Error: invalid character: '") + c + '\'') );
		}
	}

	if (m_stack.size() > 1)
		throw ( std::runtime_error(std::string("Error: inavlid expression: too many values in stack left")) );
	else if (m_stack.size() < 1)
		throw ( std::runtime_error(std::string("Error: inavlid expression: no result stored in stack")) );

	long long	result = m_stack.top();
	m_stack.pop();

	return (result);
}


/* ************************************************************************** */
/* ************************************************************************** */


void	RPN::mul(void)
{
	if (m_stack.size() < 2)
		throw( std::runtime_error("Error: Not enougth operands for multiplication") );

	long long value = m_stack.top();
	m_stack.pop();
	m_stack.top() *= value;
}

void	RPN::add(void)
{
	if (m_stack.size() < 2)
		throw( std::runtime_error("Error: Not enougth operands for addition") );

	long long value = m_stack.top();
	m_stack.pop();
	m_stack.top() += value;
}

void	RPN::sub(void)
{
	if (m_stack.size() < 2)
		throw( std::runtime_error("Error: Not enougth operands for subtraction") );

	long long value = m_stack.top();
	m_stack.pop();
	m_stack.top() -= value;
}

void	RPN::div(void)
{
	if (m_stack.size() < 2)
		throw( std::runtime_error("Error: Not enougth operands for division") );

	long long value = m_stack.top();
	m_stack.pop();
	if (value == 0)
		throw ( std::runtime_error("Error: division by 0") );

	m_stack.top() /= value;
}
