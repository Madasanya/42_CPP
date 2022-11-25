/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:52:15 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/20 23:52:15 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define COMMENTS_CANONIAL 1
#define COMMENTS_POINTS 1

#define COLOR_GREEN "\033[38;5;112m"
#define COLOR_BLUE "\033[1;94;49m"
#define COLOR_GREY "\033[1;90;49m"
#define COLOR_DEFAULT "\033[0m"
#define COLOR_PINK "\033[38;5;200m"

class ClapTrap
{
protected:
	std::string name_;
	unsigned int hitPoints_;
	unsigned int energyPoints_;
	unsigned int attackDamage_;
	unsigned int maxHitPoints_;


private:
	static const unsigned int initHitPoints_ = 10;
	static const unsigned int initEnergyPoints_ = 10;
	static const unsigned int initAttackDamage_ = 0;

public:
	ClapTrap();
	ClapTrap(const ClapTrap& obj);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap &obj);

	ClapTrap(std::string name);

	const std::string& getName() const;
	const unsigned int& getHitPoints() const;
	const unsigned int& getEnergyPoints() const;
	const unsigned int& getAttackDamage() const;

	void setName(const std::string& name);
	void setHitPoints(const unsigned int& hitPoints);
	void setEnergyPoints(const unsigned int& energyPoints);
	void setAttackDamage(const unsigned int& attackDamage);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);


};

int minValue(const int value1, const int value2);
void printPoints(ClapTrap& obj);