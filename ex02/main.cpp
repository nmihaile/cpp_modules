/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:12:42 by nmihaile          #+#    #+#             */
/*   Updated: 2024/07/17 12:01:19 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include "Fixed.hpp"

#define LIGHTRED		"\033[0;91m"
#define LIGHTGREEN		"\033[0;92m"
#define LIGHTYELLOW		"\033[0;93m"
#define LIGHTBLUE		"\033[0;94m"
#define LIGHTMAGENTA	"\033[0;95m"
#define LIGHTCYAN		"\033[0;96m"
#define DARKGRAY		"\033[0330;90m"
#define RESET			"\033[0m"

void	print_test_Header(std::string msg)
{
	std::cout << LIGHTCYAN << std::string("\n--[ ") + msg + " ]";
	for (int i = (80 - 4 - msg.length() - 2); i > 0; --i)
		std::cout << "-";
	std::cout << RESET << std::endl;
}

void	print_test_result(std::string msg, int passed, Fixed& a, Fixed& b)
{
	if (passed > 0)
		std::cout	<< LIGHTGREEN << "[OK]" << RESET << " "
					<< msg << LIGHTCYAN
					// << " [" << a << "]"
					<< RESET
					<< " ▐▐ (a, b): (" << a.toInt() << ", " << b.toInt() << ")" << std::endl;
	else
		std::cout	<< LIGHTRED << "[KO] " << msg  << LIGHTCYAN
					// << " " << " [" << a << "]"
					<< RESET
					<< " ▐▐ (a, b): (" << a.toInt() << ", " << b.toInt() << ")" << std::endl;
}

void	custom_tests(void)
{
	Fixed a = Fixed(10);
	Fixed b = Fixed(20);



	print_test_Header("TESTs COMAPARSION > < != == >= <=");
	print_test_result("B >  a", b > a, a, b);
	print_test_result("A <  b", a < b, a, b);
	print_test_result("A != b", a != b, a, b);
	
	a = b;
	if (a == b) print_test_result("A == b", a == b, a, b);
	if (a >= b) print_test_result("A >= b", a >= b, a, b);
	if (a <= b) print_test_result("A <= b", a <= b, a, b);

	print_test_Header("TESTs ADDITION & SUBSTRACTION + -");
	a = a + 5;
	if (a == 25) print_test_result("a + 5", a == 25, a, b);

	a = a - 15;
	print_test_result("a - 10", a == 10, a, b);
	
	print_test_Header("TESTs MULTIPLICATION *");
	a = a * b;
	print_test_result("a * b", a == Fixed(200), a, b);
	std::cout << "     Expected Result: " << a.toInt() << std::endl;

	Fixed ft = Fixed(21) * Fixed (2);
	print_test_result("21 * 2", ft == 42, ft, ft);


	int x = (INT_MAX >> 8) / 2;
	int y = 2;
	ft = Fixed(x) * Fixed(y);
	print_test_result("(INT_MAX >> 8 / 2) * 2", ft == x * y, ft, ft);

	print_test_Header("TESTs DIVISION /");
	Fixed c = Fixed(INT_MAX >> 8);
	Fixed d = Fixed(2);
	Fixed e = c / d;
	print_test_result("c / d", e.toInt() == ((INT_MAX >> 8) / 2), c, e);
	std::cout << "     Expected Result: " << ((INT_MAX >> 8) / 2) << std::endl;
	
	c = 100;
	d = 3;
	e = c / d;
	// Fixed r;
	// r.setRawBits(8533);
	Fixed r = Fixed(33.33203125f);
	print_test_result("c / d", e == r, c, e);
	std::cout << 100/3 << "   -> wrong int comparision" << std::endl;
	std::cout << e.getRawBits() << "   -> e's rawBits" << std::endl;
	std::cout << r.getRawBits() << "   -> r's rawBits created from calculator" << std::endl;

	print_test_Header("TESTs COMPOUND ASSIGNMENT OPERATOR +=");
	a = 1;
	a += a;
	print_test_result("a += a", a == 2, a, a);
	a += 10;
	print_test_result("a += 10", a == 12, a, a);

	print_test_Header("TESTs COMPOUND ASSIGNMENT OPERATOR -=");
	// remember the SELF-ASSIGNMENT CHECK IDIOM is not available in --c++98
	// hence a -= a; is invalid within Werror of --c++98
	a = 12;
	a -= 12;
	print_test_result("a -= a", a == 0, a, a);
	a -= 1;
	print_test_result("a -= 1", a == -1, a, a);
	
	print_test_Header("TESTs COMPOUND ASSIGNMENT OPERATOR *=");
	a = Fixed(7);
	b = Fixed(6);
	a *= b;
	print_test_result("a *= b", a == (7 * 6), a, b);
	a *= a;
	print_test_result("a *= a", a == (42 * 42), a, b);
	a = (INT_MAX >> 8) / 2;
	a *= 2;
	print_test_result("a *= a", a == ((INT_MAX >> 8) / 2) * 2, a, b);

	print_test_Header("TESTs COMPOUND ASSIGNMENT OPERATOR /=");
	a = Fixed(42);
	b = Fixed(6);
	a /= b;
	print_test_result("a /= b", a == 7, a, b);
	a = 49;
	a /= 49;
	print_test_result("a /= a", a == 49 / 49, a, b);
	a = Fixed(INT_MAX >> 8);
	a /= Fixed(2);
	b = Fixed();
	b.setRawBits(1073741696);
	print_test_result("a /= 2", a == b, a, b);
	std::cout << (((INT_MAX >> 8) / 2) << 8) << "   -> wrong int comparision" <<  std::endl;
	std::cout << a.getRawBits() << "   -> a's rawBits" << std::endl;
	std::cout << b.getRawBits() << "   -> b's rawBits created from calculator" <<  std::endl;

	print_test_Header("TESTs PRE-INCREMENT AND POST-INCREMENT ++");
	a = 0;
	b = 0;
	--b;
	if (--a == b)
		print_test_result("++a == b", 1, a, b);
	else
		print_test_result("++a == b", 0, a, b);

	--a;
	if (a++ == b)
		print_test_result("a++ == b", 1, a, b);
	else
		print_test_result("a++ == b", 0, a, b);
	
	print_test_Header("TESTs PRE-DECREMENT AND POST-DECREMENT --");
	a = 0;
	std::cout << a << " --a " << --a << " | " << a << std::endl;
	std::cout << a << " a-- " << a-- << " | " << a << std::endl;

	print_test_Header("TESTs MIN-MAX FUNCs");
	Fixed ma = Fixed(12.5f);
	Fixed mb = Fixed(12.4999f);
	std::cout << DARKGRAY << "ma int/float: " << ma.toInt() << " | " << ma << std::endl;
	std::cout << "mb int/float: " << mb.toInt() << " | " << mb << RESET << std::endl;
	print_test_result("ma=12.5 | mb=12.4999 => MIN", Fixed::min(ma, mb) == mb, a, b);
	print_test_result("ma=12.5 | mb=12.4999 => MAX", Fixed::max(ma, mb) == ma, a, b);

}

int	main(int ac, char **av)
{
	if (ac == 1)
		return ((void)av, custom_tests(), 0);
		
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	
	return (0);
}
