/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:27:39 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 00:27:39 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name_;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	void setName(const std::string& name);

};

Zombie* ZombieHorde(int N, std::string name);