/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:13:44 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/29 16:23:04 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

#include <iostream>

class RPN
{
public:
	RPN();
	~RPN();

	RPN(const RPN& other)				= delete;
	RPN&	operator=(const RPN& rhs)	= delete;

	long long	evaluate(std::string expression);
	
private:
	std::stack<long long>	m_stack;

	bool		isOperator(char c);
	long long	mul(void);
	long long	add(void);
	long long	sub(void);
	long long	div(void);
};

#endif
