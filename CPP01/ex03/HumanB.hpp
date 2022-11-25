/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:38:25 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 13:38:25 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name_;
	Weapon* weapon_;

public:
	HumanB(std::string name);
	~HumanB();
	void attack() const;
	void setWeapon(const Weapon& weapon);
};