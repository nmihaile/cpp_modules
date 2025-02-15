/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:00:59 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/08 17:30:28 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <random>
#include "Base.hpp"
#include "ABC.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
