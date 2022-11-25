/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:45:24 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 13:45:24 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const Weapon& weapon)
	:name_("John Doe"), weapon_(weapon)
{
	std::cout << name_ << " appeared" << std::endl;
}

HumanA::HumanA(std::string name, const Weapon& weapon)
	:name_(name), weapon_(weapon)
{
	std::cout << name_ << " appeared" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << name_ << " died" << std::endl;
}
void HumanA::attack() const
{
	std::cout << name_ << " attacks with their " << this->weapon_.getType() << std::endl;
}