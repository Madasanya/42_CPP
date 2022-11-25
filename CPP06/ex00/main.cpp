/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:52:12 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/01 21:52:12 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
#include <stdlib.h>
#include <stdexcept>
#include <cerrno>
#include "Conversion.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc == 2)
		{
			std::string input = argv[1];
			Conversion conv(input);
			std::cout << conv << std::endl;	
		}
		else
			return (1);
		return (0);
	}
	catch(std::invalid_argument& e)
	{
		std::cerr << "Invalid argument for conversions!" << std::endl;
	}
	catch(std::out_of_range& e)
	{
		std::cerr << "Argument out of range!" << std::endl;
	}
	catch(...)
	{
		std::cerr << "Execution failed! Reason unknown." << std::endl;
	}
}