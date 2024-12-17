/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:35:02 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/17 14:42:42 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
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
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.signForm(robotomyRequestForm);
		yoda.executeForm(robotomyRequestForm);
	}
}

void	Bureaucrat_executes_PresidentialPardonForm()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		PresidentialPardonForm presidentialPardonForm("Julian Assange");
		yoda.signForm(presidentialPardonForm);
		yoda.executeForm(presidentialPardonForm);
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
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
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
		Bureaucrat luke("Luke", ShrubberyCreationForm::REQUIRED_SIGN_GRADE);
		ShrubberyCreationForm shrubberyCreationForm("home");
		luke.signForm(shrubberyCreationForm);
	}
}

void	ShrubberyCreationForm_is_executed_by_correct_GRADE()
{
	printFunc(__func__);
	{
		Bureaucrat luke("Luke", ShrubberyCreationForm::REQUIRED_EXEC_GRADE);
		ShrubberyCreationForm shrubberyCreationForm("home");
		luke.signForm(shrubberyCreationForm);
		shrubberyCreationForm.execute(luke);
	}
}

void	ShrubberyCreationForm_gets_signed_by_Bureaucrat_with_GRADE_TOO_LOW()
{
	printFunc(__func__);
	{
		Bureaucrat intern("intern", ShrubberyCreationForm::REQUIRED_SIGN_GRADE + 1);
		ShrubberyCreationForm shrubberyCreationForm("home");
		intern.signForm(shrubberyCreationForm);
	}
}

void	ShrubberyCreationForm_Executors_GRADE_is_TOO_LOW()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		Bureaucrat intern("intern", ShrubberyCreationForm::REQUIRED_EXEC_GRADE + 1);
		ShrubberyCreationForm shrubberyCreationForm("home");
		yoda.signForm(shrubberyCreationForm);
		shrubberyCreationForm.execute(intern);
	}
}

void	ShrubberyCreationForm_fails_to_write_file()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
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
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		ShrubberyCreationForm shrubberyCreationForm("home");
		shrubberyCreationForm.execute(yoda);
	}
}

void	ShrubberyCreationForm_is_been_executed_by_Bureaucrat_with_invalid_grade()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
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
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.signForm(robotomyRequestForm);
		yoda.executeForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_is_signed_by_correct_GRADE()
{
	printFunc(__func__);
	{
		Bureaucrat luke("Luke", RobotomyRequestForm::REQUIRED_SIGN_GRADE);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		luke.signForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_is_executed_by_correct_GRADE()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		Bureaucrat luke("Luke", RobotomyRequestForm::REQUIRED_EXEC_GRADE);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.signForm(robotomyRequestForm);
		luke.executeForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_gets_signed_by_Bureaucrat_with_GRADE_TOO_LOW()
{
	printFunc(__func__);
	{
		Bureaucrat intern("intern", RobotomyRequestForm::REQUIRED_SIGN_GRADE + 1);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		intern.signForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_Executors_GRADE_is_TOO_LOW()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		Bureaucrat intern("intern", RobotomyRequestForm::REQUIRED_EXEC_GRADE + 1);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.signForm(robotomyRequestForm);
		intern.executeForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_is_been_executed_but_not_yet_sigend()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.executeForm(robotomyRequestForm);
	}
}

void	RobotomyRequestForm_is_been_executed_by_Bureaucrat_with_invalid_grade()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		RobotomyRequestForm robotomyRequestForm("R2-D2");
		yoda.signForm(robotomyRequestForm);
		std::memset(&yoda, 0, sizeof(Bureaucrat));
		yoda.executeForm(robotomyRequestForm);
	}
}

/* ************************************************************************** */

void	Instantiate_PresidentialPardonForm()
{
	printFunc(__func__);
	{
		PresidentialPardonForm presidentialPardonForm("Edward Snowden");
	}
}

void	Instantiate_PresidentialPardonForm_via_CopyConstructor()
{
	printFunc(__func__);
	{
		PresidentialPardonForm presidentialPardonForm("Edward Snowden");
		PresidentialPardonForm duplicate(presidentialPardonForm);
	}
}

void	Instantiate_PresidentialPardonForm_via_CopyConstructor_INVALID()
{
	printFunc(__func__);
	{
		PresidentialPardonForm presidentialPardonForm("Edward Snowden");
		std::memset(reinterpret_cast<void*>(&presidentialPardonForm), 0, sizeof(PresidentialPardonForm));
		PresidentialPardonForm duplicate(presidentialPardonForm);
	}
}

void	PresidentialPardonForm_getTarget_INVALID()
{
	printFunc(__func__);
	{
		PresidentialPardonForm presidentialPardonForm("Edward Snowden");
		std::memset(reinterpret_cast<void*>(&presidentialPardonForm), 0, sizeof(PresidentialPardonForm));
		std::string target =  presidentialPardonForm.getTarget();
	}
}

// void	PresidentialPardonForm_assignemnt_operator_VALID()
// {
// 	printFunc(__func__);
// 	{
// 		PresidentialPardonForm assangeForm("Julian Assange");
// 		PresidentialPardonForm snowdenForm("Edward Snowden");
// 		snowdenForm = assangeForm;
// 	}
// }

// void	PresidentialPardonForm_assignemnt_operator_INVALID()
// {
// 	printFunc(__func__);
// 	{
// 		PresidentialPardonForm assangeForm("Julian Assange");
// 		PresidentialPardonForm snowdenForm("Edward Snowden");
// 		std::memset(reinterpret_cast<void*>(&assangeForm), 0, sizeof(PresidentialPardonForm));
// 		snowdenForm = assangeForm;
// 	}
// }

void	PresidentialPardonForm_is_executed_successful()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		PresidentialPardonForm presidentialPardonForm("Edward Snowden");
		yoda.signForm(presidentialPardonForm);
		yoda.executeForm(presidentialPardonForm);
	}
}

void	PresidentialPardonForm_is_signed_by_correct_GRADE()
{
	printFunc(__func__);
	{
		Bureaucrat luke("Luke", PresidentialPardonForm::REQUIRED_SIGN_GRADE);
		PresidentialPardonForm presidentialPardonForm("Julian Assange");
		luke.signForm(presidentialPardonForm);
	}
}

void	PresidentialPardonForm_is_executed_by_correct_GRADE()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		Bureaucrat luke("Luke", PresidentialPardonForm::REQUIRED_EXEC_GRADE);
		PresidentialPardonForm presidentialPardonForm("Edward Snowden");
		yoda.signForm(presidentialPardonForm);
		luke.executeForm(presidentialPardonForm);
	}
}

void	PresidentialPardonForm_gets_signed_by_Bureaucrat_with_GRADE_TOO_LOW()
{
	printFunc(__func__);
	{
		Bureaucrat intern("intern", PresidentialPardonForm::REQUIRED_SIGN_GRADE + 1);
		PresidentialPardonForm presidentialPardonForm("Edward Snowden");
		intern.signForm(presidentialPardonForm);
	}
}

void	PresidentialPardonForm_Executors_GRADE_is_TOO_LOW()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		Bureaucrat intern("intern", PresidentialPardonForm::REQUIRED_EXEC_GRADE + 1);
		PresidentialPardonForm presidentialPardonForm("Edward Snowden");
		yoda.signForm(presidentialPardonForm);
		intern.executeForm(presidentialPardonForm);
	}
}

void	PresidentialPardonForm_is_been_executed_but_not_yet_sigend()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		PresidentialPardonForm presidentialPardonForm("Edward Snowden");
		yoda.executeForm(presidentialPardonForm);
	}
}

void	PresidentialPardonForm_is_been_executed_by_Bureaucrat_with_invalid_grade()
{
	printFunc(__func__);
	{
		Bureaucrat yoda("Yoda", Bureaucrat::HIGHEST_GRADE);
		PresidentialPardonForm presidentialPardonForm("Edward Snowden");
		yoda.signForm(presidentialPardonForm);
		std::memset(&yoda, 0, sizeof(Bureaucrat));
		yoda.executeForm(presidentialPardonForm);
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
	test(Bureaucrat_executes_PresidentialPardonForm, SUCCEDS);
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
	nl();
	test(Instantiate_PresidentialPardonForm, SUCCEDS);
	test(Instantiate_PresidentialPardonForm_via_CopyConstructor,SUCCEDS);
	test(Instantiate_PresidentialPardonForm_via_CopyConstructor_INVALID, FAILS);
	test(PresidentialPardonForm_getTarget_INVALID, FAILS);
	// test(PresidentialPardonForm_assignemnt_operator_VALID, SUCCEDS);
	// test(PresidentialPardonForm_assignemnt_operator_INVALID, FAILS);
	test(PresidentialPardonForm_is_executed_successful, SUCCEDS);
	test(PresidentialPardonForm_is_signed_by_correct_GRADE, SUCCEDS);
	test(PresidentialPardonForm_is_executed_by_correct_GRADE, SUCCEDS);
	test(PresidentialPardonForm_gets_signed_by_Bureaucrat_with_GRADE_TOO_LOW, FAILS);
	test(PresidentialPardonForm_Executors_GRADE_is_TOO_LOW, FAILS);
	test(PresidentialPardonForm_is_been_executed_but_not_yet_sigend, FAILS);
	test(PresidentialPardonForm_is_been_executed_by_Bureaucrat_with_invalid_grade, FAILS);
	nl();

	system("[ -e home_shrubbery ] && chmod 644 home_shrubbery && rm -f home_shrubbery");	// clean up
	exit(print_result());
}

int	main(int ac, char **av)
{
	system("[ -e home_shrubbery ] && chmod 644 home_shrubbery && rm -f home_shrubbery");	// clean up
	if (ac == 2 && std::strcmp(av[1], "test") == 0)
		run_tests();
	else if (ac == 2 && std::strcmp(av[1], "story") == 0)
	{

		std::cout << LIGHTYELLOW << R"(
                     ________________.  ___     .______
                    /                | /   \    |   _  \
                   |   (-----|  |----`/  ^  \   |  |_)  |
                    \   \    |  |    /  /_\  \  |      /
               .-----)   |   |  |   /  _____  \ |  |\  \-------.
               |________/    |__|  /__/     \__\| _| `.________|
                ____    __    ____  ___     .______    ________.
                \   \  /  \  /   / /   \    |   _  \  /        |
                 \   \/    \/   / /  ^  \   |  |_)  ||   (-----`
                  \            / /  /_\  \  |      /  \   \
                   \    /\    / /  _____  \ |  |\  \---)   |
                    \__/  \__/ /__/     \__\|__| `._______/

--------------------------------------------------------------------------------

                A long time ago in a galaxy far, far away...

  In a distant corner of the universe, where the forces of light and darkness
   clash, a series of bureaucratic challenges unfold. The fate of the galaxy
 often hinges on the smallest details, and the signing of forms is no exception.
  Heroes and allies navigate the complexities of official documents, each step
            crucial in their quest to maintain order and justice...

--------------------------------------------------------------------------------
		)" << RESET << std::endl;


		Bureaucrat yoda("yoda", 1);
		Bureaucrat Leia("Princess Leia", 25);
		Bureaucrat ObiWan("Obi-Wan Kenobi", 72);
		Bureaucrat Luke("Luke Skywalker", 145);

		std::cout << yoda << Leia << ObiWan << Luke << std::endl;

		ShrubberyCreationForm shrubbery("home");
		std::cout << shrubbery << std::endl;
		try	{
			Luke.signForm(shrubbery);
			Luke.executeForm(shrubbery);
		}
		catch(const std::exception& e)	{ std::cout << e.what() << std::endl; }
		try	{ ObiWan.signForm(shrubbery); }
		catch(const std::exception& e)	{ std::cout << e.what() << std::endl; }
		try	{ Leia.executeForm(shrubbery); }
		catch(const std::exception& e)	{ std::cout << e.what() << std::endl; }

		nl();

		RobotomyRequestForm r2d2("R2-D2");
		std::cout << r2d2 << std::endl;
		try	{ Luke.signForm(r2d2); }
		catch(const std::exception& e)	{ std::cout << e.what() << std::endl; }
		try	{
			ObiWan.signForm(r2d2);
			Luke.executeForm(r2d2);
		}
		catch(const std::exception& e)	{ std::cout << e.what() << std::endl; }
		try	{ ObiWan.executeForm(r2d2); }
		catch(const std::exception& e)	{ std::cout << e.what() << std::endl; }

		nl();

		PresidentialPardonForm	snowden("Edward Snowden");
		std::cout << snowden << std::endl;
		try	{ Luke.signForm(snowden); Luke.executeForm(snowden); }
		catch(const std::exception& e)	{ std::cout << e.what() << std::endl; }
		try	{ ObiWan.signForm(snowden); ObiWan.executeForm(snowden); }
		catch(const std::exception& e)	{ std::cout << e.what() << std::endl; }
		try	{ Leia.signForm(snowden); Leia.executeForm(snowden); }
		catch(const std::exception& e)	{ std::cout << e.what() << std::endl; }
		try	{ yoda.executeForm(snowden); }
		catch(const std::exception& e)	{ std::cout << e.what() << std::endl; }
		

		std::cout << LIGHTYELLOW << R"(
--------------------------------------------------------------------------------
                  _______ _    _ ______   ______ _   _ _____  
                 |__   __| |  | |  ____| |  ____| \ | |  __ \ 
                    | |  | |__| | |__    | |__  |  \| | |  | |
                    | |  |  __  |  __|   |  __| | . ` | |  | |
                    | |  | |  | | |____  | |____| |\  | |__| |
                    |_|  |_|  |_|______| |______|_| \_|_____/ 
              	
)" 		<< RESET << std::endl;

	}
	else
		std::cout << LIGHTCYAN << "usage: ./main <test|story>" << RESET << std::endl;
		
	return (0);
}
