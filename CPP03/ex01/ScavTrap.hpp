
#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
	static const unsigned int initHitPoints_ = 100;
	static const unsigned int initEnergyPoints_ = 50;
	static const unsigned int initAttackDamage_ = 20;

public:
	ScavTrap();
	ScavTrap(const ScavTrap& obj);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap &obj);

	ScavTrap(std::string name);
	void attack(const std::string& target);

	void guardGate();

};
