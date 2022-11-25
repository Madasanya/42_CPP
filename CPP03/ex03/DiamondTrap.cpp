/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:52:34 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/21 23:52:34 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap("Claptrap P. Claptrappington_clap_name")
{
	DiamondTrap::name_ = "Claptrap P. Claptrappington";
	this->hitPoints_ = FragTrap::maxHitPoints_;
	this->energyPoints_ = ScavTrap::initEnergyPoints_;
	this->attackDamage_ = FragTrap::initAttackDamage_;
	this->maxHitPoints_ = FragTrap::maxHitPoints_;
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_YELLOW << name_ << COLOR_DEFAULT << " got upgraded and wants to dance ..." << std::endl;
	printPoints(*this);
	
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
	:ClapTrap(obj.name_), ScavTrap(obj.name_), FragTrap(obj.name_)
{
	DiamondTrap::name_ = obj.name_;
	ClapTrap::name_ = obj.getName();
	this->hitPoints_ = obj.hitPoints_;
	this->energyPoints_ = obj.energyPoints_;
	this->attackDamage_ = obj.attackDamage_;
	this->maxHitPoints_ = obj.maxHitPoints_;
	if (COMMENTS_CANONIAL)
	{
		std::cout << COLOR_GREEN << this->name_ << COLOR_DEFAULT << " magically changes to ";
		std::cout << COLOR_YELLOW << obj.name_ << COLOR_DEFAULT << "."<< std::endl;
	}
	printPoints(*this);
}

DiamondTrap::~DiamondTrap()
{
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_YELLOW << name_ << COLOR_DEFAULT << " disappears forever ..." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &obj)
{
	DiamondTrap::name_ = obj.name_;
	ClapTrap::name_ = obj.getName();
	this->hitPoints_ = obj.hitPoints_;
	this->energyPoints_ = obj.energyPoints_;
	this->attackDamage_ = obj.attackDamage_;
	this->maxHitPoints_ = obj.maxHitPoints_;
	if (COMMENTS_CANONIAL)
	{
		std::cout << COLOR_YELLOW << this->name_ << COLOR_DEFAULT << " is as beautiful as ";
		std::cout << COLOR_YELLOW << obj.name_ << COLOR_DEFAULT << "."<< std::endl;
	}
	printPoints(*this);
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	DiamondTrap::name_ = name;
	this->hitPoints_ = FragTrap::maxHitPoints_;
	this->energyPoints_ = ScavTrap::initEnergyPoints_;
	this->attackDamage_ = FragTrap::initAttackDamage_;
	this->maxHitPoints_ = FragTrap::maxHitPoints_;
	if (COMMENTS_CANONIAL)
		std::cout << COLOR_YELLOW << name_ << COLOR_DEFAULT << " got upgraded and wants to dance ..." << std::endl;
	printPoints(*this);
	
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am "<< COLOR_YELLOW<< DiamondTrap::name_ << COLOR_DEFAULT << ", child of ";
	std::cout << COLOR_GREEN <<ClapTrap::name_ << COLOR_DEFAULT << "." << std::endl;

}
