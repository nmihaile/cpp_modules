/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:14:40 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/26 18:25:55 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define MAX_IDEAS 100

class Brain
{
public:
	std::string	ideas[MAX_IDEAS];
	
	Brain();
	Brain(const Brain& other);
	~Brain();

	Brain& operator = (const Brain& other);

private:
	void	deepcpy_ideas(const Brain& other);
};

#endif
