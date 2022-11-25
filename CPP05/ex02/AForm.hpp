/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:33:23 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/29 04:16:23 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name_;
	bool signStatus_;
	const int minSignGrade_;
	const int minExeGrade_;
	const std::string target_;

public:
	AForm();
	AForm(const AForm& obj);
	virtual ~AForm();
	AForm& operator=(const AForm& rhs);

	AForm(const std::string& name, const int& minSignGrade, const int& minExeGrade);
	AForm(const std::string& name, const int& minSignGrade, const int& minExeGrade, std::string target);

	void execute(const Bureaucrat& executor) const;
	virtual void action() const = 0;

	const std::string& getName() const;
	const bool& getSignStatus() const;
	const int& getMinSignGrade() const;
	const int& getMinExeGrade() const;
	const std::string& getTarget() const;

	const int& checkGrade(const int& grade, const int minGrade, const int& maxGrade) const;
	void beSigned(const Bureaucrat&  bureaucrat);

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
	class FormNotSigned: public std::exception
	{
	public:
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& ofs, const AForm& rhs);