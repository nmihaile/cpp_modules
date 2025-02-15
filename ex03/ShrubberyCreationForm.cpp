/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:29:08 by nmihaile          #+#    #+#             */
/*   Updated: 2024/12/17 11:33:04 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
	: AForm("ShrubberyCreationForm", _target, REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE)
{
	std::srand(std::time(nullptr));
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/* ************************************************************************** */
/* ************************************************************************** */


void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	validateGrade(getGradeToExec());
	if (executor.getGrade() < HIGHEST_GRADE || executor.getGrade() > LOWEST_GRADE)
		throw (std::string("Executor has INAVLID_GRADE!"));

	checkForm(executor);

	try
	{
		write_ASCII_tree();
	}
	catch(const std::exception& e)
	{
		throw ;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */


bool	ShrubberyCreationForm::write_ASCII_tree() const
{
	std::fstream	fs;
	std::string		filename = getTarget() + "_shrubbery";

	fs.open(filename, std::fstream::out | std::fstream::app);
	if (fs.is_open() == false)
		throw (std::string("Failed to open file: " + filename));

	fs << m_trees[std::rand() % 3] << "\n\n\n\n";

	if (fs.fail() || fs.bad())
		throw (std::string("Failed to write into: " + filename));
	
	fs.close();
	return (false);
}

const std::string	ShrubberyCreationForm::m_trees[3] = {
"       _-_\n"  
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\ //  ~\n"
"_- -   | | _- _\n"
"  _ -  | |   -_\n"
"      // \\\\",


"          &&& &&  & &&\n"
"      && &\\/&\\|& ()|/ @, &&\n"
"      &\\/(/&/&||/& /_/)_&/_&\n"
"   &() &\\/&|()|/&\\/ '%\" & ()\n"
"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
"&&   && & &| &| /& & % ()& /&&\n"
" ()&_---()&\\&\\|&&-&&--%---()~\n"
"     &&     \\|||\n"
"             |||\n"
"             |||\n"
"             |||\n"
"       , -=-~  .-^- _\n"
"              `",


"               ,@@@@@@@,\n"
"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
"       |o|        | |         | |\n"
"       |.|        | |         | |\n"
"    \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n"
};

