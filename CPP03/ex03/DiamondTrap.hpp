/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:47:59 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/21 23:47:59 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	static const unsigned int initHitPoints_ = 100;
	static const unsigned int initEnergyPoints_ = 100;
	static const unsigned int initAttackDamage_ = 30;
	std::string name_;

public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& obj);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap &obj);

	DiamondTrap(std::string name);
	using ScavTrap::attack;

	void whoAmI();

};
