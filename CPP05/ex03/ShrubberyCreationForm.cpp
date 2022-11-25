/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:06:03 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/29 04:11:24 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("Shrubbery Creation Form", 145, 137)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_DEFAULT << " default consturctor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj):AForm(obj.getName(), obj.getMinSignGrade(), obj.getMinExeGrade())
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_DEFAULT << " copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_DEFAULT << " destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
	if (!AForm::getName().compare(rhs.getName()))
	{
		const_cast<std::string&>(AForm::getName()) = rhs.getName();
	}
	else
	{
		std::cerr << "Incompatible Form type. Assignment failed." << std::endl;;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:AForm("Shrubbery Creation Form", 145, 147, target)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
}

void ShrubberyCreationForm::action() const
{
	if (COMMENT_FUNCTION)
		std::cout << COLOR_YELLOW << "ShrubberyPardonForm" << COLOR_DEFAULT << " action() called" << std::endl;
	std::string outfile;
	outfile = this->getTarget() + "_shrubbery";
	std::ofstream ofs(outfile.c_str());
	ofs << " _ " << std::endl;
	ofs << "| | " << std::endl;
	ofs << "| |_ _ __ ___  ___ " << std::endl;
	ofs << "| __| '__/ _ \\/ _ \\" << std::endl;
	ofs << "| |_| | |  __/  __/" << std::endl;
	ofs << " \\__|_|  \\___|\\___|" << std::endl;
	ofs.close();
}
