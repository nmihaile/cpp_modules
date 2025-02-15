/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:38:59 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/28 21:20:38 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.hpp"

std::string	ft_itostring(int i)
{
	std::ostringstream oss;
	oss << i;
	return (oss.str());
}

void	log(t_debug_type dt, std::string msg)
{
#if DEBUG_MODE
	switch (dt)
	{
		case DEBUG_LOG:
			std::cerr << LIGHTCYAN << "DEBUG: " << RESET;
			break ;
		case INFO_LOG:
			std::cerr << LIGHTBLUE << "INFO: " << RESET;
			break ;
		case WARNING_LOG:
			std::cerr << LIGHTYELLOW << "WARNING: " << RESET;
			break ;
		case ERROR_LOG:
			std::cerr << LIGHTRED << "ERROR: " << RESET;
			break ;
		default:
			std::cerr << "LOG: " << RESET;
	}
	std::cerr << DARKGRAY << msg << RESET << std::endl;
#else
	(void)dt;
	(void)msg;
#endif
}
