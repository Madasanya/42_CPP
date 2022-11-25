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
#include "Form.hpp"

int main()
{

	std::cout << std::endl << COLOR_BLUE << "*** Bureaucrat level too low ***" << COLOR_DEFAULT << std::endl;
	Bureaucrat zappo("Zappo",11);
	std::cout << zappo << std::endl;

	Form form("Base Form", 10, 100);
	form.beSigned(zappo);
	std::cout << form << std::endl;

	std::cout << std::endl << COLOR_BLUE << "*** Change of form sign status ***" << COLOR_DEFAULT << std::endl;
	zappo.promotion();
	form.beSigned(zappo);
	std::cout << form << std::endl;

	std::cout << std::endl << COLOR_BLUE << "*** Form already signed ***" << COLOR_DEFAULT << std::endl;
	form.beSigned(zappo);
	std::cout << form << std::endl;

	std::cout << std::endl << COLOR_BLUE << "*** Form constructor check ***" << COLOR_DEFAULT << std::endl;
	Form form2("Base Form II", 1000, 100);
	std::cout << form2 << std::endl;
	Form form3("Base Form III", 10, 1000);
	std::cout << form3 << std::endl;

	std::cout << std::endl << COLOR_BLUE << "*** Destructor ***" << COLOR_DEFAULT << std::endl;

}