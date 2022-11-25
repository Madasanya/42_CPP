/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:23:33 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 13:23:33 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type):type_(type)
{
	std::cout << "The creation of " << type_ << " is completed" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "The destruction of " << type_ << " is completed" << std::endl;
}

const std::string& Weapon::getType() const
{
	return(this->type_);
}

void Weapon::setType(std::string type)
{
	this->type_ = type;
}