/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:06:03 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/29 04:11:24 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("Robotomy Request Form", 72, 45)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_RED << "RobotomyRequestForm" << COLOR_DEFAULT << " default consturctor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj):AForm(obj.getName(), obj.getMinSignGrade(), obj.getMinExeGrade())
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_RED << "RobotomyRequestForm" << COLOR_DEFAULT << " copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_RED << "RobotomyRequestForm" << COLOR_DEFAULT << " destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_RED << "RobotomyRequestForm" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
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

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:AForm("Robotomy Request Form", 72, 45, target)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_RED << "RobotomyRequestForm" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
}

void RobotomyRequestForm::action() const
{
	if (COMMENT_FUNCTION)
		std::cout << COLOR_RED << "RobotomyPardonForm" << COLOR_DEFAULT << " action() called" << std::endl;
	int chance;
	chance = this->getTarget().length() % 2;
	if (chance == 0)
		std::cout << COLOR_RED << "[NOISE]" << COLOR_DEFAULT << std::endl << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << COLOR_RED << "[NOISE]"<< COLOR_DEFAULT  << std::endl << "Robotomy of "<< this->getTarget() << " failed." << std::endl;
}
