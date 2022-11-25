/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:11:22 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/21 21:11:22 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:
	static const unsigned int initHitPoints_ = 100;
	static const unsigned int initEnergyPoints_ = 100;
	static const unsigned int initAttackDamage_ = 30;

public:
	FragTrap();
	FragTrap(const FragTrap& obj);
	~FragTrap();
	FragTrap& operator=(const FragTrap &obj);

	FragTrap(std::string name);
	void attack(const std::string& target);

	void highFivesGuys();

};
