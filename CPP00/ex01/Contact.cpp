/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:59:56 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/03 18:59:56 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(void)
{
	setFirstName("");
	setLastName("");
	setNickName("");
	setPhone("");
	setDarkSecret("");
	return;
}

void Contact::fillContact ()
{
	std::string input;
	std::cout << "Enter first name:" << std::endl;
	while (std::getline(std::cin, input) && !_checkName(input))
		std::cout << "Wrong input! Enter first name:" << std::endl;
	this->setFirstName(input);
	std::cout << "Enter last name:" << std::endl;
	while (std::getline(std::cin, input) && !_checkName(input))
		std::cout << "Wrong input! Enter last name:" << std::endl;
	this->setLastName(input);
	std::cout << "Enter nickame:" << std::endl;
	while (std::getline(std::cin, input) && !_checkName(input))
		std::cout << "Wrong input! Enter nickame:" << std::endl;
	this->setNickName(input);
	std::cout << "Enter phone number:" << std::endl;
	while (std::getline(std::cin, input) && !_checkPhone(input))
		std::cout << "Wrong input! Enter phone number:" << std::endl;
	this->setPhone(input);
	std::cout << "Enter your darkest secret:" << std::endl;
	while (std::getline(std::cin, input) && !_checkSecret(input))
		std::cout << "Wrong input! Enter darkest secret:" << std::endl;
	this->setDarkSecret(input);
	Contact::_numContacts += 1;
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNickName(void) const
{
	return (this->_nickName);
}

std::string Contact::getPhone(void) const
{
	return (this->_phone);
}

std::string Contact::getDarkSecret(void) const
{
	return (this->_darkSecret);
}

void Contact::setFirstName(std::string _firstName)
{
	this->_firstName = _firstName;
}

void Contact::setLastName(std::string _lastName)
{
	this->_lastName = _lastName;
}

void Contact::setNickName(std::string _nickName)
{
	this->_nickName = _nickName;
}

void Contact::setPhone(std::string _phone)
{
	this->_phone = _phone;
}

void Contact::setDarkSecret(std::string _darkSecret)
{
	this->_darkSecret = _darkSecret;
}

int Contact::_checkName(std::string name) const
{
	for (int i = 0; name[i] != '\0'; i++)
	{
		if (!(isalpha(name[i]) || (name[i] == ' ') || (name[i] == '-')))
			return (0);
	}
	if (name.empty())
		return (0);
	return (1);
}

int Contact::_checkPhone(std::string phone) const
{
	int bracketCounter = 0;
	int digitCounter = 0;

	for (int i = 0; phone[i] != '\0'; i++)
	{
		if (phone[i] == '(')
			bracketCounter++;
		else if (phone[i] == ')')
			bracketCounter--;
		else if (isdigit(phone[i]))
			digitCounter++;
		else if ((!isdigit(phone[i]) && phone[i] != '-') || (phone[i] == '-' && \
			(phone[i + 1] == '-' || i == 0 || phone[i + 1] == '\0')))
			return (0);
		if ((bracketCounter < 0 || bracketCounter > 1) || (phone[i + 1] == '\0' && \
			(bracketCounter != 0 || digitCounter < 5)))
			return (0);
	}
	if (phone.empty())
		return (0);
	return (1);
}

int Contact::_checkSecret(std::string secret) const
{
	for (int i = 0; secret[i] != '\0'; i++)
	{
		if (!isprint(secret[i]))
			return (0);
	}
	if (secret.empty())
		return (0);
	return (1);
}

int Contact::_numContacts = 0;