/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 04:21:16 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/21 04:21:16 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:name_("CL4P-TP"), hitPoints_(initHitPoints_), energyPoints_(initEnergyPoints_), attackDamage_(initAttackDamage_)
{
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_GREEN << name_ << COLOR_DEFAULT <<"  appears in the borderlands ..." << std::endl;
	printPoints(*this);
	
}

ClapTrap::ClapTrap(const ClapTrap& obj)
	:name_(obj.getName()), hitPoints_(obj.hitPoints_), energyPoints_(obj.energyPoints_), attackDamage_(obj.attackDamage_)
{
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_GREEN << obj.getName() << COLOR_DEFAULT << " magically duplicates." << std::endl;
	printPoints(*this);
}

ClapTrap::~ClapTrap()
{
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_GREEN << name_ << COLOR_DEFAULT << " disappears forever ..." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_GREEN << this->getName() << COLOR_DEFAULT << " is as beautiful as " << COLOR_GREEN << obj.getName() << COLOR_DEFAULT << "."<< std::endl;
	this->name_ = obj.getName();
	this->hitPoints_ = obj.getHitPoints();
	this->energyPoints_ = obj.getEnergyPoints();
	this->attackDamage_ = obj.getAttackDamage();
	printPoints(*this);
	return (*this);
}

ClapTrap::ClapTrap(std::string name)
	:name_(name), hitPoints_(initHitPoints_), energyPoints_(initEnergyPoints_), attackDamage_(initAttackDamage_)
{
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_GREEN << name_ << COLOR_DEFAULT << " appears in the borderlands ..." << std::endl;
	printPoints(*this);
	
}

const std::string& ClapTrap::getName() const
{
	return (this->name_);
}

const unsigned int& ClapTrap::getHitPoints() const
{
	return (this->hitPoints_);
}

const unsigned int& ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints_);
}

const unsigned int& ClapTrap::getAttackDamage() const
{
	return (this->attackDamage_);
}


void ClapTrap::setName(const std::string& name)
{
	this->name_ = name;
}

void ClapTrap::setHitPoints(const unsigned int& hitPoints)
{
	this->hitPoints_ = hitPoints;
}

void ClapTrap::setEnergyPoints(const unsigned int& energyPoints)
{
	this->energyPoints_ = energyPoints;
}

void ClapTrap::setAttackDamage(const unsigned int& attackDamage)
{
	this->attackDamage_ = attackDamage;
}


void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints_ < 1)
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " is fatally injured and therefore can't attack." << std::endl;
	else if (energyPoints_ < 1)
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " is too tired to attack." << std::endl;
	else
	{
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " attacks ";
		std::cout << COLOR_GREEN << target << COLOR_DEFAULT << " and causes " << this->attackDamage_ << " damage."  << std::endl;
		this->energyPoints_--;
	}
	printPoints(*this);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints_ < 1)
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " is fatally injured and therefore can't take any more damage." << std::endl;
	else if (this->hitPoints_ <= amount)
	{
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " got hit by ";
		std::cout << this->hitPoints_ << " points of damage." << std::endl;
		this->hitPoints_ = 0;
	}
	else
	{
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " got hit by ";
		std::cout << amount << " points of damage." << std::endl;
		this->hitPoints_ = this->hitPoints_ - amount;
	}
	printPoints(*this);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints_ < 1)
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " is fatally injured and therefore can't repair itself." << std::endl;
	else if (this->energyPoints_ < 1)
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " is tired and therefore can't repair itself." << std::endl;
	else if (this->hitPoints_ > 9)
	{
		(this->energyPoints_)--;
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " doesn't need to be repaired and is instead given a high gloss finish. How shiny!" << std::endl;
	}
	else
	{
		(this->energyPoints_)--;
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " repairs by ";
		std::cout << minValue(10 - this->hitPoints_, 10) << " points." << std::endl;
		this->hitPoints_ = (minValue(this->hitPoints_ + amount, 10));
	}
	printPoints(*this);
}

void printPoints(ClapTrap& obj)
{
	if (COMMENTS_POINTS)
	{
		std::cout << COLOR_GREY << "Name: " << obj.getName() <<"\tHitpoints: " << obj.getHitPoints();
		std::cout << "\tEnergypoints: " << obj.getEnergyPoints() << COLOR_DEFAULT << std::endl;
	}
}

int minValue(const int value1, const int value2)
{
	if (value1 < value2)
		return (value1);
	return (value2);
}