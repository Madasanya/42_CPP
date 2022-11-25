/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:33:23 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/26 12:33:23 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:name_("Vogon"), grade_(minGrade_)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
	:name_(obj.name_), grade_(obj.grade_)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(name_) = rhs.name_;
		grade_ = rhs.grade_;
	}
	return(*this);
}


Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
	try:name_(name), grade_(checkGrade(grade, maxGrade_, minGrade_))
{
if (COMMENT_CONSTRUCTOR)
	std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
}
catch(Bureaucrat::GradeTooHighException& e)
{
	std::cerr << e.what() << "Programm terminated.\n";
}
catch(Bureaucrat::GradeTooLowException& e)
{
	std::cerr << e.what() << "Programm terminated.\n";
}

Bureaucrat::Bureaucrat(const std::string& name)
	:name_(name), grade_(minGrade_)
{
	if (COMMENT_CONSTRUCTOR)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const int& grade)
	try:name_("Vogon"), grade_(checkGrade(grade, maxGrade_, minGrade_))
{
if (COMMENT_CONSTRUCTOR)
	std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " parametric constructor called" << std::endl;

}
catch(Bureaucrat::GradeTooHighException& e)
{
	std::cerr << e.what() << "Programm terminated.\n";
}
catch(Bureaucrat::GradeTooLowException& e)
{
	std::cerr << e.what() << "Programm terminated.\n";
}


const std::string& Bureaucrat::getName() const
{
	return(name_);
}

const int& Bureaucrat::getGrade() const
{
	return(grade_);
}

void Bureaucrat::promotion()
{
	if (COMMENT_FUNCTION)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " promotion() called" << std::endl;
	try
	{
		grade_ = checkGrade(grade_ - 1, maxGrade_, minGrade_);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << "Bureaucrat promotion not possible.\n";
	}
}

void Bureaucrat::demotion()
{
	if (COMMENT_FUNCTION)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " demotion() called" << std::endl;
	try
	{
		grade_ = checkGrade(grade_ + 1, maxGrade_, minGrade_);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << "Bureaucrat demotion not possible.\n";
	}
}

const int& Bureaucrat::checkGrade(const int& grade, const int max, const int min) const
{
	if (grade < max)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > min)
		throw(Bureaucrat::GradeTooLowException());
	return(grade);
}

void Bureaucrat::signForm(const AForm& form, const std::string reason) const
{
	if (COMMENT_FUNCTION)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " signForm() called" << std::endl;
	if (reason == "")
		std::cout << COLOR_PURPLE << this->getName() << COLOR_DEFAULT << " signed " << COLOR_GREEN << form.getName() << COLOR_DEFAULT << "." << std::endl;
	else
		std::cout << COLOR_PURPLE << this->getName() << COLOR_DEFAULT << " couldn't sign " << COLOR_GREEN << form.getName() << COLOR_DEFAULT << " because " << reason << "." << std::endl;
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		if (COMMENT_FUNCTION)
			std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " executeForm() called" << std::endl;
		this->checkGrade(this->getGrade(), 1, form.getMinExeGrade());
		if (form.getSignStatus() == 0)
			throw(AForm::FormNotSigned());
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << "." << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << "Form execution failed due to wrong minimal grade provided!\n";
	}
	catch(AForm::FormNotSigned& e)
	{
		std::cerr << e.what() << "Form executon failed, because the form is not signed!\n";
	}
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade Too High: ");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade Too Low: ");
}

std::ostream& operator<<(std::ostream& ofs, const Bureaucrat& rhs)
{
	ofs << COLOR_PURPLE << rhs.getName() << COLOR_DEFAULT << ", bureaucrats grade " << COLOR_PURPLE << rhs.getGrade() << COLOR_DEFAULT << ".";
	return (ofs);
}
