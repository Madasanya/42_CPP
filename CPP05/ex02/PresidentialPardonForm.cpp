/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:06:03 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/29 04:11:24 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("Presidential Pardon Form", 25, 5)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PINK << "PresidentialPardonForm" << COLOR_DEFAULT << " default consturctor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj):AForm(obj.getName(), obj.getMinSignGrade(), obj.getMinExeGrade())
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PINK << "PresidentialPardonForm" << COLOR_DEFAULT << " copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PINK << "PresidentialPardonForm" << COLOR_DEFAULT << " destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PINK << "PresidentialPardonForm" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
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

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:AForm("Presidential Pardon Form", 25, 5, target)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PINK << "PresidentialPardonForm" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
}

void PresidentialPardonForm::action() const
{
	if (COMMENT_FUNCTION)
		std::cout << COLOR_PINK << "PresidentialPardonForm" << COLOR_DEFAULT << " action() called" << std::endl;
	std::cout <<  this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
