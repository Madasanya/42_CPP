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

int main()
{
	try
	{
		std::cout << std::endl << COLOR_BLUE << "*** Inititalization ***" << COLOR_DEFAULT << std::endl;
		Bureaucrat zappo("Zappo", 1);

		std::cout << zappo << std::endl;

		ShrubberyCreationForm shrubb("home");
		std::cout << shrubb << std::endl;
		RobotomyRequestForm robot("Zaphod Beeblebrox");
		std::cout << robot << std::endl;
		PresidentialPardonForm president("Trillian");
		std::cout << president << std::endl;


		std::cout << std::endl << COLOR_BLUE << "*** Form sign end execution ***" << COLOR_DEFAULT << std::endl;
		std::cout << std::endl << COLOR_BLUE << "*** \tShrubbery Creation Form ***" << COLOR_DEFAULT << std::endl;
		shrubb.beSigned(zappo);
		shrubb.AForm::execute(zappo);
		std::cout << std::endl << COLOR_BLUE << "*** \tRobotomy Request Form ***" << COLOR_DEFAULT << std::endl;
		robot.beSigned(zappo);
		robot.AForm::execute(zappo);
		std::cout << std::endl << COLOR_BLUE << "*** \tPresidential Pardon Form ***" << COLOR_DEFAULT << std::endl;
		president.beSigned(zappo);
		president.AForm::execute(zappo);
		
		std::cout << std::endl << COLOR_BLUE << "*** Exception testing ***" << COLOR_DEFAULT << std::endl;
		Bureaucrat zappo2("Zappo", 1000);
		std::cout << "Test" << std::endl;

		std::cout << std::endl << COLOR_BLUE << "*** Destructor ***" << COLOR_DEFAULT << std::endl;

	}	
	catch (...){}
}