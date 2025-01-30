/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:03 by nmihaile          #+#    #+#             */
/*   Updated: 2025/01/30 17:29:45 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "tester.hpp"
#include "../RPN.hpp"

typedef struct s_test
{
	std::string	expression;
	std::string expected;
}				t_test;

int	main(void)
{
	const t_test tests[] = {
		{"2 2 *", "4"},
		{"1 1 +", "2"},
		{"5 2 -", "3"},
		{"6 2 /", "3"},
		{"1 1 + -", "Error: Not enougth operands for subtraction\n"},
		{"8 9 * 9 - 9 - 9 - 4 - 1 +", "42"},
		{"7 7 * 7 -", "42"},
		{"1 2 * 2 / 2 * 2 4 - +", "0"},
		{"(1 + 1)", "Error: invalid character: '('\n"},
		{"77 7 * 7 -", "Error: too many values in stack left\n"},
		{"77 7 * 7 - -", "-35"},
		{"0 0 * ", "0"},
		{"1 1 1 1 + + +", "4"},
		{"6 0 /", "Error: division by 0\n"},
		{"6 3 3 - /", "Error: division by 0\n"},
		{"6.6 1 +", "Error: invalid character: '.'\n"},
		{"1 * 6", "Error: Not enougth operands for multiplication\n"},
		{"1 + 6", "Error: Not enougth operands for addition\n"},
		{"1 - 6", "Error: Not enougth operands for subtraction\n"},
		{"1 / 6", "Error: Not enougth operands for division\n"},


	};

	RPN rpn;

	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
		test(tests[i].expression, tests[i].expected);

	print_test_result();
	return (0);
}
