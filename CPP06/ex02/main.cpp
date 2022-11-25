/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:09:08 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/03 14:09:08 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <exception>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand (time(NULL));
	int randomNumber = rand() % 3;
	switch (randomNumber)
	{
		case (0): return (new A);
		case (1): return (new B);
		case (2): return (new C);
		default: return(NULL);
	}
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "Object is of class A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "Object is of class B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "Object is of class C" << std::endl;
	else
		std::cout << "That is not nice!" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Object is of class A" << std::endl;
	}
	catch(...)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "Object is of class B" << std::endl;
		}
		catch(...)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "Object is of class C" << std::endl;
			}
			catch(...)
			{
				std::cerr << "Bad Input" << std::endl;
			}
		}
	}
}

int main()
{
	std::cout << std::endl << "*** Test 1 ***" << std::endl;
	Base* test = generate();
	identify(test);
	identify(*test);

	std::cout << std::endl << "*** Test 2 ***" << std::endl;
	A a;
	identify(&a);
	identify(a);

	std::cout << std::endl << "*** Test 3 ***" << std::endl;
	identify(0);

	delete (test);
	return (0);
}