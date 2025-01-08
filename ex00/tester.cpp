
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>
#include "ScalarConverter.hpp"

#define BLUE			"\033[34m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

typedef struct s_TestCase
{
	std::string	input;
	std::string	expected;
}	TestCase;

std::string	captureOutput(const std::string& input)
{
	std::stringstream	buff;
	std::streambuf*		oBuff = std::cout.rdbuf(buff.rdbuf());
	std::regex			ansiEscapeCodes("\\x1b\\[[0-9;]*[mK]");

	ScalarConverter::convert(input);

	std::cout.rdbuf(oBuff);

	std::string	str = buff.str();
	str = std::regex_replace(str, ansiEscapeCodes, "");
	return (str);
}

void	runTests(void)
{
	TestCase	tests[] = {
		{"0", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n"},
		{"A", "char: 'A'\nint: 65\nfloat: 65.0f\ndouble: 65.0\n"},
		{"*", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"},
		{"042", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"},
		{"123", "char: '{'\nint: 123\nfloat: 123.0f\ndouble: 123.0\n"},
		{"~", "char: '~'\nint: 126\nfloat: 126.0f\ndouble: 126.0\n"},

		{"123.45f", "char: '{'\nint: 123\nfloat: 123.45f\ndouble: 123.45\n"},
		{"123.45", "char: '{'\nint: 123\nfloat: 123.45f\ndouble: 123.45\n"},
		{"125.456", "char: '}'\nint: 125\nfloat: 125.456f\ndouble: 125.456\n"},

		{"2147483647", "char: impossible\nint: 2147483647\nfloat: 2147483648.0f\ndouble: 2147483647.0\n"},		// float is off => has +1 => because of loss of precision
		{"2147483648", "ERROR: Invalid input\n"},
		{"-2147483648", "char: impossible\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0\n"},
		{"-2147483649", "ERROR: Invalid input\n"},

		{ "\x42", "char: 'B'\nint: 66\nfloat: 66.0f\ndouble: 66.0\n"},
		{ "\x01", "ERROR: conversion to char <1>: out of range <32, 126>\n"},
		{ "\x1F", "ERROR: conversion to char <31>: out of range <32, 126>\n"},
		{ "\x7F", "ERROR: conversion to char <127>: out of range <32, 126>\n"},
		{ "\xFF", "ERROR: conversion to char <-1>: out of range <32, 126>\n"},
		{ "\x00", "ERROR: Invalid argument: empty string\n"},

		{ "abc", "ERROR: Invalid input\n"},

		{ "\t\n\v\f\r 123 \r\f\v\n\t", "ERROR: Invalid input\n"},
		{ "123 \r\f\v\n\t", "ERROR: Invalid input\n"},
		// { "\t\n\v\f\r 123", "ERROR: Invalid input\n"},

		{ "\t\n\v\r   abc    \r\n\v\r", "ERROR: Invalid input\n"},
		{ "\t\n\v\r   47.11    \r\n\v\r", "ERROR: Invalid input\n"},
		// { "\n1", "ERROR: Invalid input\n"},
		{ "1\n", "ERROR: Invalid input\n"},
		{ "\t1\t", "ERROR: Invalid input\n"},
		{ "1  ", "ERROR: Invalid input\n"},
		{ "  1", "char: Non displayable\nint: 1\nfloat: 1.0f\ndouble: 1.0\n"},

		{ "456", "char: impossible\nint: 456\nfloat: 456.0f\ndouble: 456.0\n"},
		{ "456.", "char: impossible\nint: 456\nfloat: 456.0f\ndouble: 456.0\n"},
		{ "456.f", "char: impossible\nint: 456\nfloat: 456.0f\ndouble: 456.0\n"},
		{ "456.a", "ERROR: Invalid input\n"},
		{ ".789", "char: Non displayable\nint: 0\nfloat: 0.789f\ndouble: 0.789\n"},
		{ ".789f", "char: Non displayable\nint: 0\nfloat: 0.789f\ndouble: 0.789\n"},
		{ ".789a", "ERROR: Invalid input\n"},
		{ ".", "char: '.'\nint: 46\nfloat: 46.0f\ndouble: 46.0\n"},

		{ "nanf", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n"},
		{ "inff", "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n"},
		{ "+inff", "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n"},
		{ "-inff", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n"},

		{ "nan", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n"},
		{ "inf", "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n"},
		{ "+inf", "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n"},
		{ "-inf", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n"},

		{ std::to_string(std::numeric_limits<int>::max()), "char: impossible\nint: 2147483647\nfloat: 2147483648.0f\ndouble: 2147483647.0\n"},
		{ std::to_string(std::numeric_limits<int>::min()), "char: impossible\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0\n"},

		{ std::to_string(std::numeric_limits<float>::max()) + "f", "char: impossible\nint: impossible\nfloat: 340282346638528859811704183484516925440.0f\ndouble: 340282346638528859811704183484516925440.0\n"},
		{ std::to_string(std::numeric_limits<float>::lowest()) + "f", "char: impossible\nint: impossible\nfloat: -340282346638528859811704183484516925440.0f\ndouble: -340282346638528859811704183484516925440.0\n"},

		{ std::to_string(std::numeric_limits<double>::max()), "char: impossible\nint: impossible\nfloat: impossible\ndouble: 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0\n"},
		{ std::to_string(std::numeric_limits<double>::lowest()), "char: impossible\nint: impossible\nfloat: impossible\ndouble: -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0\n"},

		{ "1.00005", "char: Non displayable\nint: 1\nfloat: 1.00005f\ndouble: 1.00005\n" },
		{ "1.000005", "char: Non displayable\nint: 1\nfloat: 1.000005f\ndouble: 1.000005\n" },
		{ "1.0000005", "char: Non displayable\nint: 1\nfloat: 1.000000f\ndouble: 1.0000005\n" },
		{ "1.000000000000005", "char: Non displayable\nint: 1\nfloat: 1.0f\ndouble: 1.000000000000005\n" },
		{ "1.0000000000000005", "char: Non displayable\nint: 1\nfloat: 1.0f\ndouble: 1.000000000000000\n" },
		{ "1.00000000000000005", "char: Non displayable\nint: 1\nfloat: 1.0f\ndouble: 1.0\n" },
		{ "1.0000005f", "char: Non displayable\nint: 1\nfloat: 1.000000f\ndouble: 1.0000005\n" },
		{ "1.00000005f", "char: Non displayable\nint: 1\nfloat: 1.0f\ndouble: 1.0\n" }
	};

	size_t size = sizeof(tests) / sizeof(tests[0]);

	for (size_t i = 0; i < size; ++i)
	{
		std::string	result = captureOutput(tests[i].input);
		
		// Replace non-displayable-character with _
		std::string input(tests[i].input);
		std::replace(input.begin(), input.end(), '\x01', '_');
		std::replace(input.begin(), input.end(), '\n', '_');
		std::replace(input.begin(), input.end(), '\t', '_');
		std::replace(input.begin(), input.end(), '\v', '_');
		std::replace(input.begin(), input.end(), '\r', '_');
		std::replace(input.begin(), input.end(), '\x19', '_');

		std::cout	<< LIGHTCYAN << "[" << std::setw(2) << std::setfill('0') << i+1 << "]" << std::setfill(' ') << RESET
					<< "  |" << std::setw(20) << input << "|  -> ";
		if (result == tests[i].expected)
			std::cout << LIGHTGREEN << "[OK]" << RESET << std::endl;
		else
		{
			std::cout << LIGHTRED << "[KO]" << RESET << std::endl;

			std::cout << "--------------------\n"	<< "EXPECTED\n" << tests[i].expected;
			std::cout << "--------------------\n"	<< "RESULT\n" << result << std::endl;
			std::cout << "--------------------\n"		<< "SCALARCONVERTER::CONVERT()" << std::endl;
			ScalarConverter::convert(tests[i].input);

			std::cout << "--------------------\n" << std::endl;
			std::cout << LIGHTRED << "=> Test suite failed at test " << i + 1 << ": passed " << i << "/" << size << " tests.\n" << RESET << std::endl;
			return ;
		}
	}
	std::cout << LIGHTGREEN << "\n=> ALL tests passed " << size << "/" << size << " 🥳\n" << RESET << std::endl;
}

int	main(void)
{
	std::cout << BLUE << "Testing ScalarConverter …"  << RESET << std::endl;
	std::cout << BLUE << "-------------------------\n"  << RESET << std::endl;

	runTests();

	return (0);
}
