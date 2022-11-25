/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:28:27 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/26 00:28:27 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

#define COMMENT_CANONICAL 1
#define COMMENT_CONSTRUCTOR 1
#define COMMENT_FUNCTION 1

#define COLOR_GREEN "\033[38;5;112m"
#define COLOR_BLUE "\033[1;94;49m"
#define COLOR_GREY "\033[1;90;49m"
#define COLOR_DEFAULT "\033[0m"
#define COLOR_PINK "\033[38;5;200m"
#define COLOR_PURPLE "\033[38;5;135m"
#define COLOR_YELLOW "\033[38;5;220m"
#define COLOR_RED "\033[38;5;196m"

class AForm;

class Bureaucrat
{
private:
	const std::string name_;
	int grade_;
	static const int maxGrade_ = 1;
	static const int minGrade_ = 150;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rhs);

	Bureaucrat(const std::string& name, const int& grade);
	Bureaucrat(const std::string& name);
	Bureaucrat(const int& grade);

	const std::string& getName() const;
	const int& getGrade() const;


	void promotion();
	void demotion();

	const int& checkGrade(const int& grade, const int max, const int min) const;

	void signForm(const AForm& form, const std::string reason) const;

	void executeForm(const AForm& form) const;

	class GradeTooHighException: public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		const char* what() const throw();
	};


};

std::ostream& operator<<(std::ostream& ofs, const Bureaucrat& rhs);