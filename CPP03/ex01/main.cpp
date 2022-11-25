/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 04:58:58 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/21 04:58:58 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int	main(void)
{
	{
		std::cout <<  COLOR_BLUE << "*** Basic Tests and Gate Guard ***" << COLOR_DEFAULT << std::endl;
		ClapTrap	clapTrap("Clappy");
		ScavTrap	scavTrap;

		scavTrap.attack("Jack");
		clapTrap.attack("Sereena");
		scavTrap.guardGate();
		scavTrap.takeDamage(30);
		scavTrap.beRepaired(10);
		scavTrap.takeDamage(50);
		scavTrap.takeDamage(40);
		scavTrap.takeDamage(10);
		scavTrap.beRepaired(1);
		scavTrap.attack(clapTrap.getName());
		clapTrap.beRepaired(5);
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Copying ***" << COLOR_DEFAULT << std::endl;
		ScavTrap	scavTrap;

		scavTrap.takeDamage(30);
		ScavTrap	sereena2 ("SereenaCopy");
		sereena2 = scavTrap;
		sereena2.attack(scavTrap.getName());
		scavTrap.takeDamage(sereena2.getAttackDamage());
		ScavTrap	sereena3(scavTrap);

	}
	{

		std::cout << std::endl << COLOR_BLUE << "*** Repair and attack limits ***" << COLOR_DEFAULT << std::endl;
		ScavTrap	scavTrap;

		for (int i = 0; i < 50; i++)
			scavTrap.attack("random human");
		scavTrap.beRepaired(10);
		scavTrap.attack("random human");
		scavTrap.takeDamage(100);
		scavTrap.takeDamage(100);
	}
	return (0);
}