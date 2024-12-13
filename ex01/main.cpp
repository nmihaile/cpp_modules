/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:04:34 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/13 11:47:56 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "authority.h"
#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <cstring>

#define SUCCESS true
#define FAIL false
#define SuccessMSG std::string(GREEN) + std::string("Success, no exception cought.") + std::string(RESET)
#define defaultExceptionMSG std::string("Default exception caught. Please debug further.")
#define ExceptionPrefix std::string(LIGHTRED) + std::string("Exception cought: ") + std::string(RESET)

void	printFunc(const char *func) { std::cout << LIGHTCYAN << "--[ " << func << " ]--" << RESET << std::endl; }
void	printDefaultException(void) { std::cout << defaultExceptionMSG << std::endl; }
void	passed(void) { std::cout << LIGHTGREEN << "[OK] " << RESET << std::endl; }
void	failed(void) { std::cout << LIGHTRED   << "[KO] " << RESET << std::endl; }
void	nl(void) { std::cout << std::endl; }
void	Succeded_or_Failed(bool expected, bool result, std::string msg)
{
	if (expected == result)
		std::cout << LIGHTGREEN << "  [OK] " << RESET;
	else
		std::cout << LIGHTRED << "  [KO] " << RESET;
	std::cout << msg << std::endl; // << std::endl
}

void	Test_FormDefaultConstructor(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try { Form form; }
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormParameterConstructor_VALID(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try { Form form("Enrole @ 42", 42, 1); }
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormParameterConstructor_EMPTY_Name(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try { Form form("", 42, 1); }
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (std::string& e)		{ msg = ExceptionPrefix + e;					result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormParameterConstructor_INVALID_GradeToSign_01(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try { Form form("Enrole @ 42", HIGHEST_GRADE - 1, 1); }
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormParameterConstructor_INVALID_GradeToSign_02(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try { Form form("Enrole @ 42", LOWEST_GRADE + 1, 1); }
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormParameterConstructor_INVALID_GradeToExec_01(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try { Form form("Enrole @ 42", 42, HIGHEST_GRADE - 1); }
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormParameterConstructor_INVALID_GradeToExec_02(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try { Form form("Enrole @ 42", 42, LOWEST_GRADE + 1); }
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormCopyConstructor_VALID(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try {
		Form base("Enrole @ 42", 42, 42);
		Form copy(base);
	}
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormCopyConstructor_INVALID_base_class(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try {
		Form inavlid_base;
		std::memset(&inavlid_base, 0, sizeof(Form));

		Form copy(inavlid_base);
	}
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormCopyAssignmentOperator_VALID(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try {
		Form base("Enrole @ 42", 42, 42);
		Form copy;
		copy = base;
	}
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormCopyAssignmentOperator_INVALID_base_class_01(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	// This test works, mut there should go some more thoughts into it
	// if it makes sense like this, or if it has to be altered and
	// modified to mekr more sense.
	// However the test is here - so let's test it…

	printFunc(__func__);
	try {
		Form inavlid_base("Enrole @ 42", 42, 42);
		std::memset(&inavlid_base, 0, sizeof(Form));

		Form copy;
		copy = inavlid_base;
	}
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

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

void	Test_FormGetter_Name_VALID(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try {
		Form form("Enrole @ 42", 42, 42);
		std::string name = form.getName();
	}
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormGetter_Name_INVALID(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try {
		Form form("Enrole @ 42", 42, 42);
		std::memset(&form, 0, sizeof(Form));
		std::string name = form.getName();
	}
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (std::string& str)	{ msg = ExceptionPrefix + str;					result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormGetter_IsSigned_VALID(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try {
		Form form("Enrole @ 42", 42, 42);
		bool is_signed = form.isSigned();
		Bureaucrat B("Moritz", 1);
		form.beSigned(B);
		is_signed = form.isSigned();
	}
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormGetter_GetGradeToSign_VALID(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try {
		Form form("Enrole @ 42", 42, 42);
		unsigned int grade_to_sign = form.getGradeToSign();
		if (grade_to_sign != 42)
			throw (std::string("Form::getGradeToSign() faild: -> investigate"));
	}
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}

void	Test_FormGetter_GetGradeToSign_INVALID(bool expected)
{
	bool result = SUCCESS;
	std::string msg = SuccessMSG;

	printFunc(__func__);
	try {
		Form form("Enrole @ 42", 42, 42);
		std::memset(&form, 0, sizeof(Form));
		unsigned int grade_to_sign = form.getGradeToSign();
		if (grade_to_sign != 42)
			throw (std::string("Form::getGradeToSign() faild: -> investigate"));
	}
	catch (std::exception& e)	{ msg = ExceptionPrefix + e.what();				result = FAIL; }
	catch (...)					{ msg = ExceptionPrefix + defaultExceptionMSG;	result = FAIL; }
	Succeded_or_Failed(expected, result, msg);
}


int	main(void)
{
	Test_FormDefaultConstructor(SUCCESS);
	nl();
	Test_FormParameterConstructor_VALID(SUCCESS);
	Test_FormParameterConstructor_EMPTY_Name(FAIL);
	Test_FormParameterConstructor_INVALID_GradeToSign_01(FAIL);
	Test_FormParameterConstructor_INVALID_GradeToSign_02(FAIL);
	Test_FormParameterConstructor_INVALID_GradeToExec_01(FAIL);
	Test_FormParameterConstructor_INVALID_GradeToExec_02(FAIL);
	nl();
	Test_FormCopyConstructor_VALID(SUCCESS);
	Test_FormCopyConstructor_INVALID_base_class(FAIL);
	nl();
	Test_FormCopyAssignmentOperator_VALID(SUCCESS);
	Test_FormCopyAssignmentOperator_INVALID_base_class_01(SUCCESS);
	// Test_FormCopyAssignmentOperator_INVALID_base_class_02(FAIL);
	nl();
	Test_FormGetter_Name_VALID(SUCCESS);
	Test_FormGetter_Name_INVALID(FAIL);
	nl();
	Test_FormGetter_IsSigned_VALID(SUCCESS);
	nl();
	Test_FormGetter_GetGradeToSign_VALID(SUCCESS);
	Test_FormGetter_GetGradeToSign_INVALID(FAIL);

	// Form f1("Enroll @ 42", 42, 1);
	// Bureaucrat moritz("Moritz", 1);
	// Bureaucrat trainee("Trainee", 150);
	
	// std::cout << f1;
	// try
	// {
	// 	f1.beSigned(trainee);
	// }
	// catch (std::exception& e)
	// {
	// 	std::cout << e.what() << " " << trainee.getName() << " is not allowd to sign." << std::endl;
	// }
	// try
	// {
	// 	f1.beSigned(moritz);
	// }
	// catch (std::exception& e)
	// {
	// 	std::cout << e.what() << " " << moritz.getName() << " is not allowd to sign." << std::endl;
	// }
	// std::cout << f1;

	return (0);
}
