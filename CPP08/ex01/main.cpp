/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 04:43:00 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/05 06:17:34 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define COLOR_BLUE "\033[1;94;49m"
#define COLOR_DEFAULT "\033[0m"

int main()
{
	{
		std::cout << std::endl << COLOR_BLUE << "*** Mass Test ***" << COLOR_DEFAULT << std::endl;
		Span sp = Span(20000);
		sp.massFill();
		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(11);
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Example Subject Sheet ***" << COLOR_DEFAULT << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Empty array ***" << COLOR_DEFAULT << std::endl;
		Span sp = Span(0);
		sp.massFill();
		std::cout << sp;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(11);
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Copy constructor and copy assignment operator ***" << COLOR_DEFAULT << std::endl;
		Span sp1 = Span(10);
		sp1.addNumber(11);
		std::cout << "sp1: " << sp1;
		Span sp2 (sp1);
		sp2.addNumber(20);
		std::cout<< "sp2: "  << sp2;
		Span sp3 (0);
		sp3 = sp1;
		std::cout<< "sp3: "  << sp3;
		sp3.massFill();
		std::cout << "sp3: " << sp3;
		std::cout << "sp1: " << sp1;
		std::cout << sp1.shortestSpan() << std::endl;
	}
	return 0;
}