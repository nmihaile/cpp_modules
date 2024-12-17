/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:04:34 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/16 18:35:58 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include "Form.hpp"
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
#define FAIL false
#define SuccessMSG std::string(GREEN) + std::string("Success, no exception cought.") + std::string(RESET)
#define defaultExceptionMSG std::string("Default exception caught. Please debug further.")
#define ExceptionPrefix std::string(LIGHTRED) + std::string("Exception cought: ") + std::string(RESET)

void	printFunc(const char *func) { std::cout << LIGHTCYAN << "--[ " << func << " ]--" << RESET << std::endl; }
int		total_count(bool count) { static int c; if (count == true) c++; return (c); }
int		test_passed(bool count) { static int c; if (count == true) c++; return (c); }
void	nl(void) { std::cout << std::endl; }
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

void	FormDefaultConstructor(void)
{
	printFunc(__func__);
	{
		Form form;
	}
}

/* ************************************************************************** */

void	FormParameterConstructor_VALID(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", 42, 1);
	}
}

void	FormParameterConstructor_EMPTY_Name(void)
{
	printFunc(__func__);
	{
		Form form("", 42, 1);
	}
}

void	FormParameterConstructor_INVALID_GradeToSign_01(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", HIGHEST_GRADE - 1, 1);
	}
}

void	FormParameterConstructor_INVALID_GradeToSign_02(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", LOWEST_GRADE + 1, 1);
	}
}

void	FormParameterConstructor_INVALID_GradeToExec_01(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", 42, HIGHEST_GRADE - 1);
	}
}

void	FormParameterConstructor_INVALID_GradeToExec_02(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", 42, LOWEST_GRADE + 1);
	}
}

/* ************************************************************************** */

void	FormCopyConstructor_VALID(void)
{
	printFunc(__func__);
	{
		Form base("Enrole @ 42", 42, 42);
		Form copy(base);
	}
}

void	FormCopyConstructor_INVALID_base_class(void)
{
	printFunc(__func__);
	{
		Form inavlid_base;
		std::memset(&inavlid_base, 0, sizeof(Form));

		Form copy(inavlid_base);
	}
}

/* ************************************************************************** */

void	FormCopyAssignmentOperator_VALID(void)
{
	printFunc(__func__);
	{
		Form base("Enrole @ 42", 42, 42);
		Form copy;
		// This is now invalid, because I set the operatoe=() to =delete;
		// copy = base;
	}
}

void	FormCopyAssignmentOperator_INVALID_base_class_01(void)
{
	// This test works, mut there should go some more thoughts into it
	// if it makes sense like this, or if it has to be altered and
	// modified to mekr more sense.
	// However the test is here - so let's test it…
	printFunc(__func__);
	{
		Form inavlid_base("Enrole @ 42", 42, 42);
		std::memset(&inavlid_base, 0, sizeof(Form));

		Form copy;
		// This is now invalid, because I set the operatoe=() to =delete;
		// copy = inavlid_base;
	}
}

// void	FormCopyAssignmentOperator_INVALID_base_class_02(void)
// {
// 	// with the new test() func this TEST does NOT work anymore !!!!
// 	// befor it kinda worked BUT:
// 	// This test executes like this on macOS, and SEGV on Linux
// 	// on macOS is_signed is 0
// 	// on Linux is_signed is 42
// 	//
// 	// so this test is probably way out of scope for this exercise
// 	// and much more thought has to go into it, to make it worth while
// 	printFunc(__func__);
// 	{
// 		Form inavlid_base("Enrole @ 42", 42, 42);
// 		std::memset(&inavlid_base, 42, sizeof(Form));

// 		Form copy;
// 		copy = inavlid_base;
// 	}
// }

// void	Test_FormCopyAssignmentOperator_INVALID_base_class_02(bool expected)
// {
// 	bool result = SUCCESS;
// 	std::string msg = SuccessMSG;

// 	// This test executes like this on macOS, and SEGV on Linux
// 	// on macOS is_signed is 0
// 	// on Linux is_signed is 42
// 	//
// 	// so this test is probably way out of scope for this exercise
// 	// and much more thought has to go into it, to make it worth while

// 	printFunc(__func__);
// 	try {
// 		Form inavlid_base("Enrole @ 42", 42, 42);
// 		std::memset(&inavlid_base, 42, sizeof(Form));

// 		Form copy;
// 		copy = inavlid_base;
// 	}
// 	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
// 	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
// 	Succeded_or_Failed(expected, result, msg);
// }

/* ************************************************************************** */

void	FormGetter_Name_VALID(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", 42, 42);
		std::string name = form.getName();
	}
}

void	FormGetter_Name_INVALID(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", 42, 42);
		std::memset(&form, 0, sizeof(Form));
		std::string name = form.getName();
	}
}

/* ************************************************************************** */

void	FormGetter_IsSigned_VALID(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", 42, 42);
		bool is_signed = form.isSigned();
		Bureaucrat ceo("CEO", 1);
		form.beSigned(ceo);
		is_signed = form.isSigned();
	}
}

/* ************************************************************************** */

void	FormGetter_GetGradeToSign_VALID(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", 42, 42);
		unsigned int grade_to_sign = form.getGradeToSign();
		if (grade_to_sign != 42)
			throw (std::string("Form::getGradeToSign() faild: -> investigate"));
	}
}

void	FormGetter_GetGradeToSign_INVALID(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", 42, 42);
		std::memset(&form, 0, sizeof(Form));
		unsigned int grade_to_sign = form.getGradeToSign();
		if (grade_to_sign != 42)
			throw (std::string("Form::getGradeToSign() faild: -> investigate"));
	}
}

/* ************************************************************************** */

void	FormGetter_GetGradeToExec_VALID(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", 42, 42);
		unsigned int grade_to_exec = form.getGradeToExec();
		if (grade_to_exec != 42)
			throw (std::string("Form::getGradeToExec() faild: -> investigate"));
	}
}

void	FormGetter_GetGradeToExec_INVALID(void)
{
	printFunc(__func__);
	{
		Form form("Enrole @ 42", 42, 42);
		std::memset(&form, 0, sizeof(Form));
		unsigned int grade_to_exec = form.getGradeToExec();
		if (grade_to_exec != 42)
			throw (std::string("Form::getGradeToExec() faild: -> investigate"));
	}
}

/* ************************************************************************** */

void	Form_BeSigned_VALID(void)
{
	printFunc(__func__);
	{
		Bureaucrat ceo("CEO", 1);
		Form form("Enrole @ 42", 42, 42);
		form.beSigned(ceo);
	}
}

void	Form_BeSigned_INVALID_AlreadySigned(void)
{
	printFunc(__func__);
	{
		Bureaucrat ceo("CEO", 1);
		Bureaucrat employee("Employee", 42);
		Form form("Enrole @ 42", 42, 42);
		form.beSigned(employee);
		form.beSigned(ceo);
	}
}

void	Form_BeSigned_INVALID_LowGrade(void)
{
	printFunc(__func__);
	{
		Bureaucrat b("Intern", 150);
		Form form("Enrole @ 42", 42, 42);
		form.beSigned(b);
	}
}

void	Form_BeSigned_INVALID_InvalidBureaucratGrade(void)
{
	printFunc(__func__);
	{
		Bureaucrat b("Invalid", 42);
		std::memset(&b, 0, sizeof(Bureaucrat));
		Form form("Enrole @ 42", 42, 42);
		form.beSigned(b);
	}
}

/* ************************************************************************** */

void	Bureaucrat_SignForm_VALID(void)
{
	printFunc(__func__);
	{
		Bureaucrat employee("Employee", 42);
		Form enrole("Enrole @ 42", 42, 42);
		employee.signForm(enrole);
	}
}

void	Bureaucrat_SignForm_INVALID_GradeTooLow(void)
{
	printFunc(__func__);
	{
		Bureaucrat intern("Intern", 150);
		Form enrole("Enrole @ 42", 42, 42);
		intern.signForm(enrole);
	}
}

void	Bureaucrat_SignForm_INVALID_AlreadySigned(void)
{
	printFunc(__func__);
	{
		Bureaucrat ceo("CEO", 1);
		Bureaucrat employee("Employee", 42);
		Form enrole("Enrole @ 42", 42, 42);
		ceo.signForm(enrole);
		employee.signForm(enrole);
	}
}

void	Bureaucrat_SignForm_INVALID_InvalidGrade(void)
{
	printFunc(__func__);
	{
		Bureaucrat invalid("Invalid", 42);
		std::memset(&invalid, 0, sizeof(Bureaucrat));
		Form enrole("Enrole @ 42", 42, 42);
		invalid.signForm(enrole);
	}
}

void	run_tests(void)
{
	test(FormDefaultConstructor, SUCCESS);
	nl();
	test(FormParameterConstructor_VALID, SUCCESS);
	test(FormParameterConstructor_EMPTY_Name, FAIL);
	test(FormParameterConstructor_INVALID_GradeToSign_01, FAIL);
	test(FormParameterConstructor_INVALID_GradeToSign_02, FAIL);
	test(FormParameterConstructor_INVALID_GradeToExec_01, FAIL);
	test(FormParameterConstructor_INVALID_GradeToExec_02, FAIL);
	nl();
	test(FormCopyConstructor_VALID, SUCCESS);
	test(FormCopyConstructor_INVALID_base_class, FAIL);
	nl();
	// test(FormCopyAssignmentOperator_VALID, SUCCESS);
	// test(FormCopyAssignmentOperator_INVALID_base_class_01, SUCCESS);
	// // test(FormCopyAssignmentOperator_INVALID_base_class_02, FAIL);
	nl();
	test(FormGetter_Name_VALID, SUCCESS);
	test(FormGetter_Name_INVALID, FAIL);
	nl();
	test(FormGetter_IsSigned_VALID, SUCCESS);
	nl();
	test(FormGetter_GetGradeToSign_VALID, SUCCESS);
	test(FormGetter_GetGradeToSign_INVALID, FAIL);
	nl();
	test(FormGetter_GetGradeToExec_VALID, SUCCESS);
	test(FormGetter_GetGradeToExec_INVALID, FAIL);
	nl();
	test(Form_BeSigned_VALID, SUCCESS);
	test(Form_BeSigned_INVALID_AlreadySigned, FAIL);
	test(Form_BeSigned_INVALID_LowGrade, FAIL);
	test(Form_BeSigned_INVALID_InvalidBureaucratGrade, FAIL);
	nl();
	test(Bureaucrat_SignForm_VALID, SUCCESS);
	test(Bureaucrat_SignForm_INVALID_GradeTooLow, FAIL);
	test(Bureaucrat_SignForm_INVALID_AlreadySigned, FAIL);
	test(Bureaucrat_SignForm_INVALID_InvalidGrade, FAIL);

	nl();
	if (total_count(false) == test_passed(false))
	{
		std::cout << "  🎉🥳 All tests passed! 🥳🎉" << std::endl;
		std::cout << LIGHTGREEN << "══════════════════════════════" << RESET << std::endl;
	}
	else
	{
		std::cout << "  ❌ " << test_passed(false) << "/" << total_count(false) << " tests passed!" << std::endl;
		std::cout << "     please investigate and debug further…" << std::endl;
		std::cout << LIGHTRED << "═══════════════════════════════════════════════" << RESET << std::endl;
	}
	nl();
	exit(total_count(false) == test_passed(false));
}

void	run_story()
{
	nl();

	Form enrole("Enroll @ 42", 42, 1);
	Bureaucrat moritz("Moritz", 1);
	Bureaucrat patrick("Patrick", 42);
	Bureaucrat intern("Intern", 150);
	
	std::cout << enrole;
	try
	{
		enrole.beSigned(intern);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << " " << intern.getName() << " is not allowd to sign." << std::endl;
	}

	try
	{
		moritz.signForm(enrole);
	}
	catch (std::exception& e)
	{
		std::cout << moritz.getName() << " tried to sign " << enrole.getName() << ": " << e.what() << std::endl;
	}

	try
	{
		patrick.signForm(enrole);
	}
	catch (std::exception& e)
	{
		std::cout << patrick.getName() << " tried to sign " << enrole.getName() << ", BUT: " << e.what() << std::endl;
	}

	std::cout << enrole;

	nl();
}

int	main(int ac, char **av)
{

	if (ac == 2 && std::strcmp(av[1], "test") == 0)
		run_tests();
	else if (ac == 2 && std::strcmp(av[1], "story") == 0)
		run_story();
	else
		std::cout << LIGHTCYAN << "usage: ./main <test|story>" << RESET << std::endl;
	return (0);
}
