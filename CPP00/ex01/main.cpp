/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:57:31 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/03 18:57:31 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

static	std::string strToUpper(std::string str)
	{
		for (int i = 0; str[i] != '\0'; i++)
			str[i] = (char)std::toupper(str[i]);
		return (str);
	}

int main()
{
	PhoneBook phonebook;
	std::string cmd;

	std::cout << "Welcome to your personal phonebook!" << std::endl;
	std::cout << "You can use the following commands: ADD, SEARCH or EXIT" << std::endl;
	while (std::getline(std::cin, cmd) && strToUpper(cmd) != "EXIT")
	{
		if (strToUpper(cmd) == "ADD")
			phonebook.add();
		else if (strToUpper(cmd) == "SEARCH")
			phonebook.search();
		else
			std::cout << "Please add correct command!" << std::endl;
		std::cout << "You can use the following commands: ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}