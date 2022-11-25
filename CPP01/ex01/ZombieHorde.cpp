/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 01:37:31 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 01:37:31 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name)
{
	Zombie* zombieHorde = new Zombie[N];
	for(int i = 0; i < N; i++)
		zombieHorde[i].setName(name);
	return(zombieHorde);
}