/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:33:23 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/29 05:01:36 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	:name_("Base Form"),
	signStatus_(0),
	minSignGrade_(150),
	minExeGrade_(150),
	target_("")
{
	if(COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "AForm" << COLOR_DEFAULT << " default constructor called" << std::endl;
}

AForm::AForm(const AForm& obj)
	:name_(obj.name_),
	signStatus_(obj.signStatus_),
	minSignGrade_(obj.minSignGrade_),
	minExeGrade_(obj.minExeGrade_),
	target_(obj.target_)
{
	if(COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "AForm" << COLOR_DEFAULT << " copy constructor called" << std::endl;
}

AForm::~AForm()
{
	if(COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "AForm" << COLOR_DEFAULT << " destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
	if(COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "AForm" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
	const_cast<std::string&>(name_) = rhs.name_;
	signStatus_ = rhs.signStatus_;
	const_cast<int&>(minSignGrade_) = rhs.minSignGrade_;
	const_cast<int&>(minExeGrade_) = rhs.minExeGrade_;
	const_cast<std::string&>(target_) = rhs.target_;
	return(*this);
}

AForm::AForm(const std::string& name, const int& minSignGrade, const int& minExeGrade)
	try: name_(name),
		signStatus_(0),
		minSignGrade_(checkGrade(minSignGrade, 150, 1)),
		minExeGrade_(checkGrade(minExeGrade, 150, 1)),
		target_("")
	{/* function body */
	if(COMMENT_CONSTRUCTOR)
		std::cout << COLOR_GREEN << "Form" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << "Form creatin failed due to wrong maximum grade provided!\n";
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << "Form creatin failed due to wrong minimal grade provided!\n";
	}

AForm::AForm(const std::string& name, const int& minSignGrade, const int& minExeGrade, std::string target)
	try:name_(name),
	signStatus_(0),
	minSignGrade_(minSignGrade),
	minExeGrade_(minExeGrade),
	target_(target)
	{
	if(COMMENT_CONSTRUCTOR)
		std::cout << COLOR_GREEN << "Form" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << "Form creation failed due to wrong maximum grade provided!\n";
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << "Form creation failed due to wrong minimal grade provided!\n";
	}

void AForm::execute(const Bureaucrat& executor) const
{
	try
	{
		if(COMMENT_CONSTRUCTOR)
			std::cout << COLOR_GREEN << "Form" << COLOR_DEFAULT << " execute() called" << std::endl;
		executor.checkGrade(executor.getGrade(), 1, this->getMinExeGrade());
		if (this->getSignStatus() == 0)
			throw(AForm::FormNotSigned());
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << "Form execution failed due to wrong minimal grade provided!\n";
	}
	catch(AForm::FormNotSigned& e)
	{
		std::cerr << e.what() << "Form executon failed, because the form is not signed!\n";
	}
	this->action();
}

const std::string& AForm::getName() const
{
	return(this->name_);
}

const bool& AForm::getSignStatus() const
{
	return(this->signStatus_);
}

const int& AForm::getMinSignGrade() const
{
	return(this->minSignGrade_);
}

const int& AForm::getMinExeGrade() const
{
	return(this->minExeGrade_);
}

const std::string& AForm::getTarget() const
{
	return(this->target_);
}

const int& AForm::checkGrade(const int& grade, const int minGrade, const int& maxGrade) const
{
	if (grade < maxGrade)
		throw(AForm::GradeTooHighException());
	else if (grade > minGrade)
		throw(AForm::GradeTooLowException());
	return(grade);
}

void AForm::beSigned(const Bureaucrat&  bureaucrat)
{
	if (COMMENT_FUNCTION)
		std::cout << COLOR_GREEN << "AForm" << COLOR_DEFAULT << " beSigned() called" << std::endl;
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
		std::cerr << e.what() << "Bureaucrat couldn't sign because his level is too low.\n";
		return;
	}
	this->signStatus_ = 1;
	bureaucrat.signForm(*this, "");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("Grade Too High: ");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade Too Low: ");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return("Form not signed: ");
}

std::ostream& operator<<(std::ostream& ofs, const AForm& rhs)
{
	ofs << "Name: " + rhs.getName() <<  "\nSign Status: " << rhs.getSignStatus() << "\nRequired grade to sign: " << rhs.getMinSignGrade() << "\nRequired grade to execute:" << rhs.getMinExeGrade() << ".";
	return (ofs);
}
