/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonetaryValue.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:32:36 by nmihaile          #+#    #+#             */
/*   Updated: 2025/02/13 17:33:50 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonetaryValue.hpp"

template <typename T>
T	MonetaryValue::strToType(const std::string& _value)
{
	std::stringstream	ss(_value);
	T					parsedValue;

	ss >> parsedValue;
	if (ss.fail())
		throw ( std::runtime_error("failed to convert str to monetary value") );

	return (parsedValue);
}
