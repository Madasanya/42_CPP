/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:58:12 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 18:58:12 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl enters the shop!" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl finally left." << std::endl;
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning()

{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}


static int getIndex(std::string type)
{
	std::string	types[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int index = 0;
	while (index < 4)
	{
		if (types[index] == type)
			break;
		index++;
	}
	return (index);
}

static int importance(std::string level, std::string filter)
{
	int levelIndex = getIndex(level);
	int filterIndex = getIndex(filter);
	if (filterIndex > 3 && levelIndex > 3)
		return(IRRELEVANT);
	if (((levelIndex - filterIndex) >= 0 && levelIndex < 4) || filterIndex > 3)
		return(IMPORTANT);
	return (FILTER);
}

void Harl::complain(std::string level, std::string filter)
{
	void (Harl::*fct[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	switch (importance(level, filter))
	{
		case FILTER:
			break;
		case IMPORTANT:
			(this->*(fct[getIndex(level)]))();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << std::endl;
			break;
	}
}