/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:30:56 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/29 20:30:56 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_GREY << "Intern" << COLOR_DEFAULT << " default constructor called" << std::endl;
}

Intern::Intern(const Intern& obj)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_GREY << "Intern" << COLOR_DEFAULT << " copy consturtor called" << std::endl;
	*this = obj;
}

Intern::~Intern()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_GREY << "Intern" << COLOR_DEFAULT << " destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_GREY << "Intern" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
	(void)rhs;
	return(*this);
}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	try
	{
		if (COMMENT_FUNCTION)
			std::cout << COLOR_GREY << "Intern" << COLOR_DEFAULT << " makeForm() called" << std::endl;
		std::string	forms[3] = {"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
		for (int i = 0; i < 3; i++)
		{
			if (!(forms[i].compare(form)))
			{
				switch (i)
				{
					case 0:
						return (new ShrubberyCreationForm(target));
					case 1:
						return (new RobotomyRequestForm(target));
					case 2:
						return (new PresidentialPardonForm(target));
				}
			}
		}
		throw(Intern::FormNotFound());
	}
	catch(Intern::FormNotFound& e)
	{
		std::cerr << e.what() << "Intern couldn't create form!\n";
		throw(Intern::FormNotFound());
	}
	return (NULL);
}

const char* Intern::FormNotFound::what() const throw()
{
	return("Form not found: ");
}