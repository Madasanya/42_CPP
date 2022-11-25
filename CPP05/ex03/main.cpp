/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:28:21 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/26 00:28:21 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		std::cout << std::endl << COLOR_BLUE << "*** Initialization ***" << COLOR_DEFAULT << std::endl;
		Bureaucrat zappo("Zappo", 1);
		std::cout << zappo << std::endl;
		Intern intern;

		std::cout << std::endl << COLOR_BLUE << "*** \tShrubbery Creation Form ***" << COLOR_DEFAULT << std::endl;
		AForm* form_ptr = intern.makeForm("Shrubbery Creation Form", "home");
		(*form_ptr).beSigned(zappo);
		(*form_ptr).AForm::execute(zappo);
		delete (form_ptr);

		std::cout << std::endl << COLOR_BLUE << "*** \tRobotomy Request Form ***" << COLOR_DEFAULT << std::endl;
		AForm* form_ptr2 = intern.makeForm("Robotomy Request Form", "Zaphod Beeblebrox");
		(*form_ptr2).beSigned(zappo);
		(*form_ptr2).AForm::execute(zappo);
		delete (form_ptr2);

		std::cout << std::endl << COLOR_BLUE << "*** \tPresidential Pardon Form ***" << COLOR_DEFAULT << std::endl;
		AForm* form_ptr3 = intern.makeForm("Presidential Pardon Form", "Trillian");
		(*form_ptr3).beSigned(zappo);
		(*form_ptr3).AForm::execute(zappo);
		delete (form_ptr3);

		std::cout << std::endl << COLOR_BLUE << "*** \tUnknown Form ***" << COLOR_DEFAULT << std::endl;
		AForm* form_ptr4 = intern.makeForm("A38", "home");
		(*form_ptr4).beSigned(zappo);
		(*form_ptr4).AForm::execute(zappo);
		delete (form_ptr4);
	}	
	catch (...)
	{}
}