/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:28:07 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/11 18:53:22 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl Hal;

	Hal.complain("debug");
	Hal.complain("info");
	Hal.complain("warning");
	Hal.complain("error");

	Hal.complain("whoops");

	Hal.complain("ErRoR");

	return (0);
}

