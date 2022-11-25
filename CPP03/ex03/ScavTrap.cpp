/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:23:50 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/21 16:23:50 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap("Sereena")
{
	this->hitPoints_ = initHitPoints_;
	this->energyPoints_ = initEnergyPoints_;
	this->attackDamage_ = initAttackDamage_;
	this->maxHitPoints_ = initHitPoints_;
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_PINK << name_ << COLOR_DEFAULT << " got upgraded and goes straight to Up Over Bar ..." << std::endl;
	printPoints(*this);
	
}

ScavTrap::ScavTrap(const ScavTrap& obj)
	:ClapTrap(obj.name_)
{
	this->hitPoints_ = obj.hitPoints_;
	this->energyPoints_ = obj.energyPoints_;
	this->attackDamage_ = obj.attackDamage_;
	this->maxHitPoints_ = obj.maxHitPoints_;
	if (COMMENTS_CANONIAL)
	{
		std::cout << COLOR_GREEN << obj.getName() << COLOR_DEFAULT << " magically changes to ";
		std::cout << COLOR_PINK << obj.getName() << COLOR_DEFAULT << "."<< std::endl;
	}
	printPoints(*this);
}

ScavTrap::~ScavTrap()
{
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_PINK << name_ << COLOR_DEFAULT << " disappears forever ..." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
{
	if (COMMENTS_CANONIAL)
	{
		std::cout << COLOR_PINK << this->getName() << COLOR_DEFAULT << " is as beautiful as ";
		std::cout << COLOR_PINK << obj.getName() << COLOR_DEFAULT << "."<< std::endl;
	}
	this->name_ = obj.getName();
	this->hitPoints_ = obj.getHitPoints();
	this->energyPoints_ = obj.getEnergyPoints();
	this->attackDamage_ = obj.getAttackDamage();
	this->maxHitPoints_ = obj.maxHitPoints_;
	printPoints(*this);
	return (*this);
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	//this->name_ = name;
	this->hitPoints_ = initHitPoints_;
	this->energyPoints_ = initEnergyPoints_;
	this->attackDamage_ = initAttackDamage_;
	this->maxHitPoints_ = initHitPoints_;
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_PINK << name_ << COLOR_DEFAULT << " got upgraded goes straight to Up Over Bar ..." << std::endl;
	printPoints(*this);
	
}
void ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints_ < 1)
	{
		std::cout << COLOR_PINK << this->name_ << COLOR_DEFAULT;
		std::cout << " is fatally injured and therefore can't attack." << std::endl;
	}
	else if (energyPoints_ < 1)
		std::cout << COLOR_PINK << this->name_ << COLOR_DEFAULT << " is too tired to attack." << std::endl;
	else
	{
		std::cout << COLOR_PINK << this->name_ << COLOR_DEFAULT << " attacks ";
		std::cout << COLOR_PINK << target << COLOR_DEFAULT << " with a Shuriken and causes ";
		std::cout << this->attackDamage_ << " damage."  << std::endl;
		this->energyPoints_--;
	}
	printPoints(*this);
}

void ScavTrap::guardGate()
{
	std::cout << COLOR_PINK << this->name_ << COLOR_DEFAULT << " stands protectively ";
	std::cout << "in front of the back door and lets no one through." << std::endl;
}
