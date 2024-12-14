/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:56:09 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/14 20:38:18 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
	: AForm(_target, 72, 75)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


const std::string	drill_sounds[20] = {
	"Brr",
	"Vrr",
	"Zzz",
	"Drr",
	"Tkk",
	"Krk",
	"Grr",
	"Bzz",
	"Prr",
	"Trr",
	"Zrk",
	"Brk",
	"...",
	"Zzt",
	"Dzk",
	"Vnk",
	"Tzz",
	"Rrt",
	"Grk",
	"Dzt"
};
