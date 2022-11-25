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

int main()
{
	std::cout << std::endl << COLOR_BLUE << "*** Inits with correct and with wrong value ***" << COLOR_DEFAULT << std::endl;
	Bureaucrat zappo("Zappo",-1);
	std::cout << zappo << std::endl;
	Bureaucrat bureaucrat(1);
	std::cout << bureaucrat << std::endl;
	Bureaucrat carl(151);
	std::cout << carl << std::endl;

	std::cout << std::endl << COLOR_BLUE << "*** Pro/Demotion with correct and with wrong value ***" << COLOR_DEFAULT << std::endl;
	

	zappo.demotion();
	std::cout << zappo << std::endl;
	bureaucrat.promotion();
	std::cout << bureaucrat << std::endl;
	carl.promotion();
	std::cout << carl << std::endl;
	bureaucrat.demotion();
	std::cout << bureaucrat << std::endl;

	std::cout << std::endl << COLOR_BLUE << "*** Destructor ***" << COLOR_DEFAULT << std::endl;
}