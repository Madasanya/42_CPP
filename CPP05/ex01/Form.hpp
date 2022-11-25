/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:33:23 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/26 12:33:23 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name_;
	bool signStatus_;
	const int minSignGrade_;
	const int minExeGrade_;

public:
	Form();
	Form(const Form& obj);
	~Form();
	Form& operator=(const Form& rhs);

    Form(const std::string& name, const int& minSignGrade, const int& minExeGrade);

	const std::string& getName() const;
	const bool& getSignStatus() const;
	const int& getMinSignGrade() const;
	const int& getMinExeGrade() const;

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
};

std::ostream& operator<<(std::ostream& ofs, const Form& rhs);