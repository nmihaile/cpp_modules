/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:55:13 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/21 13:04:09 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"


int	main(void)
{
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	// while (!mstack.empty())
	// {
	// 	std::cout << mstack.top() << std::endl;
	// 	mstack.pop();
	// }

	for (MutantStack<int>::iterator it = mstack.begin(); it < mstack.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	
	return (0);
}
