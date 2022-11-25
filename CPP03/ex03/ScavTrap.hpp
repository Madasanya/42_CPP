/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:11:14 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/21 21:11:14 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
protected:
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
