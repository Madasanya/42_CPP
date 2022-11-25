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
	Zombie rob;
	rob.announce();

	Zombie cadavres("Cadavres");
	cadavres.announce();

	Zombie* p = newZombie("P");
	p->announce();
	delete (p);
	
	randomChump("Astrale");


	
	return (0);
}