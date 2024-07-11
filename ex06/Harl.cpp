/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:39:01 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/11 21:45:48 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	m_complain_level = -1;
}

Harl::~Harl()
{	
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Harl::set_filter(std::string level)
{
	const std::string	complains[COMPLAIN_COUNT] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < COMPLAIN_COUNT; i++)
		if (complains[i].compare(this->capitalize_level(level)) == 0)
		{
			m_complain_level = i;
			return ;
		}
	m_complain_level = -1;
}

void	Harl::complain(void)
{
	switch (m_complain_level)
	{
		case DEBUG_LEVEL:
			this->debug();
			// fall through
		case INFO_LEVEL:
			this->info();
			// fall through
		case WARNING_LEVEL:
			this->warning();
			// fall through
		case ERROR_LEVEL:
			this->error();
			break ;
		default:
			this->no_complain();
			break ;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Harl::debug(void)
{
	std::cout
	<< LIGHTBLUE
	<< MSG_BORDER
	<< "[ DEBUG ]\n"
	<< RESET
	<< HAL_DEBUG
	<< LIGHTBLUE
	<< MSG_BORDER
	<< RESET
	<< std::endl;
}

void	Harl::info(void)
{
	std::cout
	<< LIGHTCYAN
	<< MSG_BORDER
	<< "[ INFO ]\n"
	<< RESET
	<< HAL_INFO
	<< LIGHTCYAN
	<< MSG_BORDER
	<< RESET
	<< std::endl;
}

void	Harl::warning(void)
{
	std::cout
	<< LIGHTYELLOW
	<< MSG_BORDER
	<< "[ WARNING ]\n"
	<< RESET
	<< HAL_WARNING
	<< LIGHTYELLOW
	<< MSG_BORDER
	<< RESET
	<< std::endl;
}

void	Harl::error(void)
{
	std::cout
	<< LIGHTRED
	<< MSG_BORDER
	<< "[ ERROR ]\n"
	<< RESET
	<< HAL_ERROR
	<< LIGHTRED
	<< MSG_BORDER
	<< RESET
	<< std::endl;
}

void	Harl::no_complain(void)
{
	std::cout
	<< MSG_BORDER
	<< "[ NO COMPLAIN ]\n"
	<< HAL_NO_COMPLAIN
	<< MSG_BORDER
	<< std::endl;	
}

std::string	Harl::capitalize_level(std::string str)
{
	for (std::string::iterator it = str.begin(); it < str.end(); it++)
		*it = std::toupper(*it);
	return (str);
}
