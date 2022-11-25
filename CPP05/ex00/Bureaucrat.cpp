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
	if (COMMENt_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
	:name_(obj.name_), grade_(obj.grade_)
{
	if (COMMENt_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	if (COMMENt_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (COMMENt_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(name_) = rhs.name_;
		grade_ = rhs.grade_;
	}
	return(*this);
}


Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
	:name_(name), grade_(grade)
{
	if (COMMENt_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
	try
	{
		grade_ = checkGrade(grade, maxGrade_, minGrade_);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		grade_ = 150;
		std::cerr << e.what() << "Initital value therefore was set to 150 during creation.\n";
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		grade_ = 150;
		std::cerr << e.what() << "Initital value therefore was set to 150 during creation.\n";
	}
}

Bureaucrat::Bureaucrat(const std::string& name)
	:name_(name), grade_(minGrade_)
{
	if (COMMENt_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const int& grade)
	:name_("Vogon")
{
	if (COMMENt_CANONICAL)
		std::cout << COLOR_PURPLE << "Bureaucrat" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
	try
	{
		grade_ = checkGrade(grade, maxGrade_, minGrade_);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		grade_ = 150;
		std::cerr << e.what() << "Initital value therefore was set to 150 during creation.\n";
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		grade_ = 150;
		std::cerr << e.what() << "Initital value therefore was set to 150 during creation.\n";
	}
}


const std::string& Bureaucrat::getName() const
{
	return(name_);
}

const int& Bureaucrat::getGrade() const
{
	return(grade_);
}

const int& Bureaucrat::checkGrade(const int& grade, const int max, const int min)
{
	if (grade < max)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > min)
		throw(Bureaucrat::GradeTooLowException());
	return(grade);
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
