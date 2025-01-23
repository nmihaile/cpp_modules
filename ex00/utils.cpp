/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:00:25 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/23 17:05:31 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	exit_with_msg(std::string msg, int exit_code)
{
	std::cout << msg << std::endl;
	exit(exit_code);
}
