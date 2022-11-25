/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:25:34 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/05 18:25:34 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <time.h>
#include "easyfind.hpp"
#define COLOR_BLUE "\033[1;94;49m"
#define COLOR_DEFAULT "\033[0m"

void printContainerInt(int value)
{
	std::cout << "[ " << value << " ]";
}

int main()
{
	{
		std::cout << std::endl << COLOR_BLUE << "*** Basic Test (List) ***" << COLOR_DEFAULT << std::endl;
		srand(time(NULL));
		int valueToSearch = 3;
		std::list<int> lst;
		for (int i = 1; i <= 20; i++)
			lst.push_back(std::rand() % 10);
		std::cout << "Container content: ";
		for_each(lst.begin(), lst.end(), printContainerInt);
		std::cout << std::endl;
		try
		{
			std::cout << "Index of first occurence of " << valueToSearch << " is: [ " << std::distance(lst.begin(), easyfind(lst, valueToSearch)) << " ]" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << ": Value not found in array\n";
		}
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Basic Test (Vector) ***" << COLOR_DEFAULT << std::endl;
		srand(time(NULL));
		int valueToSearch = 3;
		std::vector<int> vec;
		for (int i = 1; i <= 20; i++)
			vec.push_back(std::rand() % 10);
		std::cout << "Container content: ";
		for_each(vec.begin(), vec.end(), printContainerInt);
		std::cout << std::endl;
		try
		{
			std::cout << "Index of first occurence of " << valueToSearch << " is: [ " << std::distance(vec.begin(), easyfind(vec, valueToSearch)) << " ]" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << ": Value not found in array\n";
		}
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Basic Test (Deque) ***" << COLOR_DEFAULT << std::endl;
		srand(time(NULL));
		int valueToSearch = 3;
		std::deque<int> deq;
		for (int i = 1; i <= 20; i++)
			deq.push_back(std::rand() % 10);
		std::cout << "Container content: ";
		for_each(deq.begin(), deq.end(), printContainerInt);
		std::cout << std::endl;
		try
		{
			std::cout << "Index of first occurence of " << valueToSearch << " is: [ " << std::distance(deq.begin(), easyfind(deq, valueToSearch)) << " ]" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << ": Value not found in array\n";
		}
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Value not in Array ***" << COLOR_DEFAULT << std::endl;
		std::list<int> lst;
		int valueToSearch = 3;
		lst.push_back(5);
		lst.push_back(4);
		lst.push_back(2);
		lst.push_back(1);
		lst.push_back(7);
		std::cout << "Container content: ";
		for_each(lst.begin(), lst.end(), printContainerInt);
		std::cout << std::endl;
		try
		{
			std::cout << std::distance(lst.begin(), easyfind(lst, valueToSearch)) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << ": Value not found in array.\n";
		}
	}
}