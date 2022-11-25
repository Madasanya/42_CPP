/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:27:33 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 00:27:33 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

	Zombie::Zombie():name_("")
	{
		std::cout << "The Army of the Undead welcomes its newest member " << name_ << std::endl;
	}

	Zombie::Zombie(std::string name):name_(name)
	{
		std::cout << "The Army of the Undead welcomes its newest member " << name_ << std::endl;
	}

	Zombie::~Zombie()
	{
		std::cout << name_ << " starved due to the lack of tasty braiiiinnnzzzZ" <<std::endl;
	}

	void Zombie::announce(void)
	{
		std::cout << name_ << ": BraiiiinnnzzzZ..." <<std::endl;
	}

	void Zombie::setName(const std::string& name)
	{
		name_ = name;
	}