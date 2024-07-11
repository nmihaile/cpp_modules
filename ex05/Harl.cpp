/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:39:01 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/11 18:48:59 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{	
}

Harl::~Harl()
{	
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Harl::complain(std::string level)
{
	const std::string complains[COMPLAIN_COUNT] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*func[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < COMPLAIN_COUNT; i++)
		if (complains[i].compare(this->capitalize_level(level)) == 0)
		{
			(this->*func[i])();
			return ;
		}
	this->no_complain();
}


/* ************************************************************************** */
/* ************************************************************************** */


void	Harl::debug(void)
{
	std::cout	<< LIGHTBLUE
				<< MSG_BORDER
				<< HAL_DEBUG
				<< MSG_BORDER << RESET
				<< std::endl;
}

void	Harl::info(void)
{
	std::cout	<< LIGHTCYAN
				<< MSG_BORDER
				<< HAL_INFO
				<< MSG_BORDER << RESET
				<< std::endl;
}

void	Harl::warning(void)
{
	std::cout	<< LIGHTYELLOW
				<< MSG_BORDER
				<< HAL_WARNING
				<< MSG_BORDER << RESET
				<< std::endl;
}

void	Harl::error(void)
{
	std::cout	<< LIGHTRED
				<< MSG_BORDER
				<< HAL_ERROR
				<< MSG_BORDER << RESET
				<< std::endl;
}

void	Harl::no_complain(void)
{
	std::cout	<< MSG_BORDER
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
