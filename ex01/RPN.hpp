/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:13:44 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/29 15:18:58 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

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
};

#endif
