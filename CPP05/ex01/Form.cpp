/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:33:23 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/26 12:33:23 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	:name_("Base Form"), signStatus_(0), minSignGrade_(150), minExeGrade_(150)
{
	if(COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "Form" << COLOR_DEFAULT << " default constructor called" << std::endl;
}

Form::Form(const Form& obj)
	:name_(obj.name_), signStatus_(obj.signStatus_), minSignGrade_(obj.minSignGrade_), minExeGrade_(obj.minExeGrade_)
{
	if(COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "Form" << COLOR_DEFAULT << " copy constructor called" << std::endl;
}

Form::~Form()
{
	if(COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "Form" << COLOR_DEFAULT << " destructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
	if(COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "Form" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
	const_cast<std::string&>(name_) = rhs.name_;
	signStatus_ = rhs.signStatus_;
	const_cast<int&>(minSignGrade_) = rhs.minSignGrade_;
	const_cast<int&>(minExeGrade_) = rhs.minExeGrade_;
	return(*this);
}

Form::Form(const std::string& name, const int& minSignGrade, const int& minExeGrade)
	:name_(name), signStatus_(0), minSignGrade_(minSignGrade), minExeGrade_(minExeGrade)
{
	if(COMMENT_CONSTRUCTOR)
		std::cout << COLOR_GREEN << "Form" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
	try
	{
		const_cast<int&>(minSignGrade_) = checkGrade(minSignGrade, 150, 1);
	}
	catch(Form::GradeTooHighException& e)
	{
		const_cast<int&>(minSignGrade_) = 150;
		std::cerr << e.what() << "Form minimal signing grade wrong! Automatically set to 150.\n";
	}
	catch(Form::GradeTooLowException& e)
	{
		const_cast<int&>(minSignGrade_) = 150;
		std::cerr << e.what() << "Form minimal signing grade wrong! Automatically set to 150.\n";
	}
	try
	{
		const_cast<int&>(minExeGrade_) = checkGrade(minExeGrade, 150, 1);
	}
	catch(Form::GradeTooHighException& e)
	{
		const_cast<int&>(minExeGrade_) = 150;
		std::cerr << e.what() << "Form minimal execution grade wrong! Automatically set to 150.\n";
	}
	catch(Form::GradeTooLowException& e)
	{
		const_cast<int&>(minExeGrade_) = 150;
		std::cerr << e.what() << "Form minimal execution grade wrong! Automatically set to 150.\n";
	}
}

const std::string& Form::getName() const
{
	return(this->name_);
}

const bool& Form::getSignStatus() const
{
	return(this->signStatus_);
}

const int& Form::getMinSignGrade() const
{
	return(this->minSignGrade_);
}

const int& Form::getMinExeGrade() const
{
	return(this->minExeGrade_);
}

const int& Form::checkGrade(const int& grade, const int minGrade, const int& maxGrade) const
{
	if (grade < maxGrade)
		throw(Form::GradeTooHighException());
	else if (grade > minGrade)
		throw(Form::GradeTooLowException());
	return(grade);
}

void Form::beSigned(const Bureaucrat&  bureaucrat)
{
	if (COMMENT_FUNCTION)
		std::cout << COLOR_GREEN << "Form" << COLOR_DEFAULT << " beSigned() called" << std::endl;
	if (this->getSignStatus() == 1)
	{
		bureaucrat.signForm(*this, "the form is already signed");
		return;
	}
	try
	{
		checkGrade(bureaucrat.getGrade(), this->getMinSignGrade(), 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "Bureaucrat couldn't sign.\n";
		bureaucrat.signForm(*this, "his level is too low");
		return;
	}
	this->signStatus_ = 1;
	bureaucrat.signForm(*this, "");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade Too High: ");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade Too Low: ");
}

std::ostream& operator<<(std::ostream& ofs, const Form& rhs)
{
	ofs << "Name: " + rhs.getName() <<  "\nSign Status: " << rhs.getSignStatus() << "\nRequired grade to sign: " << rhs.getMinSignGrade() << "\nRequired grade to execute:" << rhs.getMinExeGrade() << ".";
	return (ofs);
}
