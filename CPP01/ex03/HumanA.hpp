/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:38:25 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 13:38:25 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name_;
	const Weapon& weapon_;

public:
	HumanA(const Weapon& weapon);
	HumanA(std::string name, const Weapon& weapon);
	~HumanA();
	void attack() const;
};