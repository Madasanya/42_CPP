/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:23:50 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/21 16:23:50 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap("FR4G-TP")
{
	this->hitPoints_ = initHitPoints_;
	this->energyPoints_ = initEnergyPoints_;
	this->attackDamage_ = initAttackDamage_;
	this->maxHitPoints_ = initHitPoints_;
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_PURPLE << name_ << COLOR_DEFAULT << " got upgraded and goes straight into killing mode ..." << std::endl;
	printPoints(*this);
	
}

FragTrap::FragTrap(const FragTrap& obj)
	:ClapTrap(obj.name_)
{
	this->hitPoints_ = obj.hitPoints_;
	this->energyPoints_ = obj.energyPoints_;
	this->attackDamage_ = obj.attackDamage_;
	this->maxHitPoints_ = obj.maxHitPoints_;
	if (COMMENTS_CANONIAL)
	{
		std::cout << COLOR_GREEN << obj.getName() << COLOR_DEFAULT << " magically changes to ";
		std::cout << COLOR_PURPLE << obj.getName() << COLOR_DEFAULT << "."<< std::endl;
	}
	printPoints(*this);
}

FragTrap::~FragTrap()
{
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_PURPLE << name_ << COLOR_DEFAULT << " disappears forever ..." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &obj)
{
	if (COMMENTS_CANONIAL)
	{
		std::cout << COLOR_PURPLE << this->getName() << COLOR_DEFAULT << " is as beautiful as ";
		std::cout << COLOR_PURPLE << obj.getName() << COLOR_DEFAULT << "."<< std::endl;
	}
	this->name_ = obj.getName();
	this->hitPoints_ = obj.getHitPoints();
	this->energyPoints_ = obj.getEnergyPoints();
	this->attackDamage_ = obj.getAttackDamage();
	this->maxHitPoints_ = obj.maxHitPoints_;
	printPoints(*this);
	return (*this);
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	this->hitPoints_ = initHitPoints_;
	this->energyPoints_ = initEnergyPoints_;
	this->attackDamage_ = initAttackDamage_;
	this->maxHitPoints_ = initHitPoints_;
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_PURPLE << name_ << COLOR_DEFAULT << " got upgraded and goes straight into killing mode ..." << std::endl;
	printPoints(*this);
	
}
void FragTrap::attack(const std::string& target)
{
	if (this->hitPoints_ < 1)
	{
		std::cout << COLOR_PURPLE << this->name_ << COLOR_DEFAULT;
		std::cout << " is fatally injured and therefore can't attack." << std::endl;
	}
	else if (energyPoints_ < 1)
		std::cout << COLOR_PURPLE << this->name_ << COLOR_DEFAULT << " is too tired to attack." << std::endl;
	else
	{
		std::cout << COLOR_PURPLE << this->name_ << COLOR_DEFAULT << " attacks ";
		std::cout << COLOR_PURPLE << target << COLOR_DEFAULT << " with Hyperion Punch and causes ";
		std::cout << this->attackDamage_ << " damage."  << std::endl;
		this->energyPoints_--;
	}
	printPoints(*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << COLOR_PURPLE << this->name_ << COLOR_DEFAULT << " thinks you deserve ";
	std::cout << "a high five and raises his arm. ヘ( ^o^)ノ＼(^_^ )" << std::endl;
}
