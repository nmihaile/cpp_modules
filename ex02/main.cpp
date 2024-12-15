/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:35:02 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/15 16:38:30 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#define GREEN			"\033[32m"
#define BLUE			"\033[34m"
#define LIGHTRED		"\033[91m"
#define LIGHTGREEN		"\033[92m"
#define LIGHTYELLOW		"\033[93m"
#define LIGHTBLUE		"\033[94m"
#define LIGHTMAGENTA	"\033[95m"
#define LIGHTCYAN		"\033[96m"
#define RESET			"\033[0m"

#define SUCCESS true
#define SUCCEDS true
#define FAILS false
#define FAIL  false
#define SuccessMSG std::string(GREEN) + std::string("Success, no exception cought.") + std::string(RESET)
#define defaultExceptionMSG std::string("Default exception caught. Please debug further.")
#define ExceptionPrefix std::string(LIGHTRED) + std::string("Exception cought: ") + std::string(RESET)

std::string	funcStr(std::string str)
{
	for (std::string::iterator it = str.begin(); it < str.end(); ++it)
		if (*it == '_')
			*it = ' ';
	return str;
}
int		total_count(bool count) { static int c; if (count == true) c++; return (c); }
int		test_passed(bool count) { static int c; if (count == true) c++; return (c); }
void	nl(void) { std::cout << std::endl; }
void	printFunc(const char *func) {
	std::cout	<< LIGHTCYAN << "->" << LIGHTBLUE << "[" 
				<< std::setfill('0') << std::setw(2) << total_count(false)+1 << "] " << LIGHTCYAN
				<< funcStr(func) << " " << RESET << std::endl;
}
void	Succeded_or_Failed(bool expected, bool result, std::string msg)
{
	total_count(true);
	if (expected == result)
	{
		test_passed(true);
		std::cout << LIGHTGREEN << "  [OK] " << RESET;
	}
	else
		std::cout << LIGHTRED << "  [KO] " << RESET;
	std::cout << msg << std::endl; // << std::endl
}
int	print_result()
{
	int	res = (total_count(false) == test_passed(false));
	nl();
	if (res)
	{
		std::cout << "  🎉🥳 All " << std::setw(2) << total_count(false) <<" tests passed! 🥳🎉" << std::endl;
		std::cout << LIGHTGREEN << "══════════════════════════════════" << RESET << std::endl;
	}
	else
	{
		std::cout << "  ❌ " << test_passed(false) << "/" << total_count(false) << " tests passed!" << std::endl;
		std::cout << "     please investigate and debug acordingly…" << std::endl;
		std::cout << LIGHTRED << "══════════════════════════════════════════════════" << RESET << std::endl;
	}
	nl();
	return (res);
}


void	test(void f(void), bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	try { f(); }
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (std::string& e)		{ msg = ExceptionPrefix + e;					result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

/* ************************************************************************** */
/* ******************************  TESTS  *********************************** */
/* ************************************************************************** */

void	Bureaucrat_executes_ShrubberyCreationForm()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		ShrubberyCreationForm shrubberyCreationForm("home");
		yoda.signForm(shrubberyCreationForm);
		yoda.executeForm(shrubberyCreationForm);
		system("[ -e home_shrubbery ] && chmod 644 home_shrubbery && rm -f home_shrubbery");
	}
}

void	Bureaucrat_executes_RobotomyRequestForm()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.signForm(robotomyRequestForm);
		yoda.executeForm(robotomyRequestForm);
	}
}

/* ************************************************************************** */

void	Instantiate_ShrubberyCreationForm()
{
	printFunc(__func__);
	{
		ShrubberyCreationForm shrubberyCreationForm("Home");
	}
}

void	ShrubberyCreationForm_writes_file()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		ShrubberyCreationForm shrubberyCreationForm("home");
		yoda.signForm(shrubberyCreationForm);
		shrubberyCreationForm.execute(yoda);
		std::fstream	fs;
		fs.open("home_shrubbery");
		if (fs.is_open() != true)
		{
			throw (std::string("Test failed."));
			return ;
		}
		system("rm -f home_shrubbery");
		fs.close();
	}
}

void	ShrubberyCreationForm_is_signed_by_correct_GRADE()
{
	printFunc(__func__);
	{
		Bureaucrat luke("Luke", 145);
		ShrubberyCreationForm shrubberyCreationForm("home");
		luke.signForm(shrubberyCreationForm);
	}
}

void	ShrubberyCreationForm_is_executed_by_correct_GRADE()
{
	printFunc(__func__);
	{
		Bureaucrat luke("Luke", 137);
		ShrubberyCreationForm shrubberyCreationForm("home");
		luke.signForm(shrubberyCreationForm);
		shrubberyCreationForm.execute(luke);
	}
}

void	ShrubberyCreationForm_gets_signed_by_Bureaucrat_with_GRADE_TOO_LOW()
{
	printFunc(__func__);
	{
		Bureaucrat intern("intern", 146);
		ShrubberyCreationForm shrubberyCreationForm("home");
		intern.signForm(shrubberyCreationForm);
	}
}

void	ShrubberyCreationForm_Executors_GRADE_is_TOO_LOW()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		Bureaucrat intern("intern", 138);
		ShrubberyCreationForm shrubberyCreationForm("home");
		yoda.signForm(shrubberyCreationForm);
		shrubberyCreationForm.execute(intern);
	}
}

void	ShrubberyCreationForm_fails_to_write_file()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		ShrubberyCreationForm shrubberyCreationForm("home");
		yoda.signForm(shrubberyCreationForm);

		// Delete the file if present
		system("[ -e home_shrubbery ] && rm -f home_shrubbery");

		// create file and block it
		std::ofstream	outfile("home_shrubbery");
		outfile.close();
		system("chmod 000 home_shrubbery");
		
		std::fstream	fs;
		try
		{
			shrubberyCreationForm.execute(yoda);
			std::cout << "I AM HERE" << std::endl;
		}
		catch (std::exception& e)
		{
			system("chmod 644 home_shrubbery");
			system("rm -f home_shrubbery");
			throw ;
			return ;
		}
	}
}

void	ShrubberyCreationForm_is_been_executed_but_not_yet_sigend()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		ShrubberyCreationForm shrubberyCreationForm("home");
		shrubberyCreationForm.execute(yoda);
	}
}

void	ShrubberyCreationForm_is_been_executed_by_Bureaucrat_with_invalid_grade()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		ShrubberyCreationForm shrubberyCreationForm("home");
		yoda.signForm(shrubberyCreationForm);
		std::memset(&yoda, 0, sizeof(Bureaucrat));
		shrubberyCreationForm.execute(yoda);
	}
}

/* ************************************************************************** */

void	Instantiate_RobotomyRequestForm()
{
	printFunc(__func__);
	{
		RobotomyRequestForm robotomyRequestForm("R2-D2");
	}
}

void	RobotomyRequestForm_is_executed_successful()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.signForm(robotomyRequestForm);
		yoda.executeForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_is_signed_by_correct_GRADE()
{
	printFunc(__func__);
	{
		Bureaucrat luke("Luke", 72);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		luke.signForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_is_executed_by_correct_GRADE()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		Bureaucrat luke("Luke", 75);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.signForm(robotomyRequestForm);
		luke.executeForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_gets_signed_by_Bureaucrat_with_GRADE_TOO_LOW()
{
	printFunc(__func__);
	{
		Bureaucrat intern("intern", 73);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		intern.signForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_Executors_GRADE_is_TOO_LOW()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		Bureaucrat intern("intern", 76);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.signForm(robotomyRequestForm);
		intern.executeForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_is_been_executed_but_not_yet_sigend()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.executeForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_is_been_executed_by_Bureaucrat_with_invalid_grade()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", 1);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.signForm(robotomyRequestForm);
		std::memset(&yoda, 0, sizeof(Bureaucrat));
		yoda.executeForm(robotomyRequestForm);
	}
}

/* ************************************************************************** */

void	run_tests(void)
{
	// clean expected files for test
	system("[ -e home_shrubbery ] && chmod 644 home_shrubbery && rm -f home_shrubbery");

	test(Bureaucrat_executes_ShrubberyCreationForm, SUCCEDS);
	system("[ -e home_shrubbery ] && chmod 644 home_shrubbery && rm -f home_shrubbery");	// clean up
	test(Bureaucrat_executes_RobotomyRequestForm, SUCCEDS);
	nl();
	test(Instantiate_ShrubberyCreationForm, SUCCEDS);
	test(ShrubberyCreationForm_writes_file, SUCCEDS);
	test(ShrubberyCreationForm_is_signed_by_correct_GRADE, SUCCEDS);
	test(ShrubberyCreationForm_is_executed_by_correct_GRADE, SUCCEDS);
	test(ShrubberyCreationForm_gets_signed_by_Bureaucrat_with_GRADE_TOO_LOW, FAILS);
	test(ShrubberyCreationForm_Executors_GRADE_is_TOO_LOW, FAILS);
	test(ShrubberyCreationForm_fails_to_write_file, FAILS);
	system("[ -e home_shrubbery ] && chmod 644 home_shrubbery && rm -f home_shrubbery");	// clean up
	test(ShrubberyCreationForm_is_been_executed_but_not_yet_sigend, FAILS);
	test(ShrubberyCreationForm_is_been_executed_by_Bureaucrat_with_invalid_grade, FAILS);
	nl();
	test(RobotomyRequestForm_is_executed_successful, SUCCEDS);
	test(RobotomyRequestForm_is_signed_by_correct_GRADE, SUCCEDS);
	test(RobotomyRequestForm_is_executed_by_correct_GRADE, SUCCEDS);
	test(RobotomyRequestForm_gets_signed_by_Bureaucrat_with_GRADE_TOO_LOW, FAILS);
	test(RobotomyRequestForm_Executors_GRADE_is_TOO_LOW, FAILS);
	test(RobotomyRequestForm_is_been_executed_but_not_yet_sigend, FAILS);
	test(RobotomyRequestForm_is_been_executed_by_Bureaucrat_with_invalid_grade, FAILS);

	// system("chmod 644 home_shrubbery && rm -f home_shrubbery");
	
	exit(print_result());
}

int	main()	// int ac, char **av
{
	// if (ac == 2 && std::strcmp(av[1], "test") == 0)
		run_tests();
	// else
	// 	RobotomyRequestForm_is_executed_successful();
		
	return (0);
}
