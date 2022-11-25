/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:35:45 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 17:35:45 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):name_(name), weapon_(NULL)
{
	std::cout << name_ << " appeared" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << name_ << " died" << std::endl;
}
void HumanB::attack() const
{
	if (this->weapon_ == NULL)
		std::cout << "HumanB has no weapon" << std::endl;
	else
		std::cout << this->name_ << " attacks with their " << (this->weapon_)->getType() << std::endl;
	return ;
}

void HumanB::setWeapon(const Weapon& weapon)
{
	weapon_ = (Weapon *)&weapon;
}