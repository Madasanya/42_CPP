/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:51:36 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 00:51:36 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* zombieHorde = ZombieHorde(5, "Paul");	
	for(int i = 0; i < 5; i++)
		zombieHorde[i].announce();
	delete[] zombieHorde;
	return (0);
}