/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:57:44 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/03 18:57:44 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::add(void)
{
	phoneBook[Contact::_numContacts % PHONEBOOK_SIZE].fillContact();
	return;
}

void PhoneBook::search(void) const
{
	int entries;

	entries = this->_printPBSummary();
	this->_printPBIndex(entries);
	return ;
}

int PhoneBook::_printPBSummary(void) const
{
	int entries = 0;

	std::cout << "__________ __________ __________ __________" << std::endl;
    std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
	std::cout << "---------- ---------- ---------- ----------" << std::endl;

	for(int i = 0; i < PHONEBOOK_SIZE; i++)
	{
		if (phoneBook[i].getFirstName() != "")
		{
			std::cout << std::setfill (' ') << std::setw (10) << (i + 1) << "|";
			if (phoneBook[i].getFirstName().length() <= 10)
				std::cout << std::setfill (' ') << std::setw (10) << phoneBook[i].getFirstName() << "|";
			else
				std::cout << phoneBook[i].getFirstName().substr(0, 9) << ".|" ;
			if (phoneBook[i].getLastName().length() <= 10)
				std::cout << std::setfill (' ') << std::setw (10) << phoneBook[i].getLastName() << "|";
			else
				std::cout << phoneBook[i].getLastName().substr(0, 9) << ".|" ;
			if (phoneBook[i].getNickName().length() <= 10)
				std::cout << std::setfill (' ') << std::setw (10) << phoneBook[i].getNickName() << std::endl;
			else
				std::cout << phoneBook[i].getNickName().substr(0, 9) << "." << std::endl;
			entries = i + 1;
		}
	}
	return (entries);
}

void PhoneBook::_printPBIndex(int entries) const
{
	std::string index;
	int int_index;
	
	if (phoneBook[0].getFirstName() == "")
	{
		std::cout << "No contact to be shown. Please create a contact first!" << std::endl;
		return;
	}
	std::cout << "Enter valid index:" << std::endl;
	while (std::getline(std::cin, index))
	{
		std::stringstream convert(index);

		if ( !(convert >> int_index) )
			int_index = 0;
		if (int_index > 0 && int_index <= entries)
		{
			std::cout << std::setfill (' ') << std::setw (20) << "First Name: " << phoneBook[int_index - 1].getFirstName() << std::endl;
			std::cout <<  std::setfill (' ') << std::setw (20) << "Last Name: " <<phoneBook[int_index - 1].getLastName() << std::endl;
			std::cout << std::setfill (' ') << std::setw (20) << "Nickname: " << phoneBook[int_index - 1].getNickName() << std::endl;
			std::cout << std::setfill (' ') << std::setw (20) << "Phone: " << phoneBook[int_index - 1].getPhone() << std::endl;
			std::cout << std::setfill (' ') << std::setw (20) << "Secret: " << phoneBook[int_index - 1].getDarkSecret() << std::endl;
			break;
		}
		else
			std::cout << "Wrong input! Enter valid index:" << std::endl;
	}
	return ;
}
