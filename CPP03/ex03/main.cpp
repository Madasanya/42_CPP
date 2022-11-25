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
#include "DiamondTrap.hpp"
#include "DiamondTrap.hpp"


int	main(void)
{		
	{
		std::cout <<  COLOR_BLUE << "*** Basic Tests ***" << COLOR_DEFAULT << std::endl;
		ClapTrap	clapTrap("Clappy");
		DiamondTrap	diamondTrap;

		diamondTrap.attack("Jack");
		clapTrap.attack("Sereena");
		diamondTrap.takeDamage(30);
		diamondTrap.beRepaired(10);
		diamondTrap.takeDamage(50);
		diamondTrap.takeDamage(40);
		diamondTrap.takeDamage(10);
		diamondTrap.beRepaired(1);
		diamondTrap.attack(clapTrap.getName());
		clapTrap.beRepaired(5);
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Copying ***" << COLOR_DEFAULT << std::endl;
		DiamondTrap	diamondTrap;

		diamondTrap.takeDamage(30);
		DiamondTrap	diamond2 ("DiamondTrapCopy");
		diamond2 = diamondTrap;
		diamond2.attack(diamondTrap.getName());
		diamondTrap.takeDamage(diamond2.getAttackDamage());
		DiamondTrap	diamond3(diamondTrap);
	}
	{

		std::cout << std::endl << COLOR_BLUE << "*** Repair and attack limits ***" << COLOR_DEFAULT << std::endl;
		DiamondTrap	diamondTrap;

		for (int i = 0; i < 50; i++)
			diamondTrap.attack("Jack");
		diamondTrap.beRepaired(10);
		diamondTrap.attack("Jack");
		diamondTrap.takeDamage(100);
		diamondTrap.takeDamage(100);
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Special Class functions ***" << COLOR_DEFAULT << std::endl;
		DiamondTrap	diamondTrap("Diamond");

		diamondTrap.whoAmI();
		diamondTrap.attack("me");
		diamondTrap.guardGate();
		diamondTrap.highFivesGuys();
		diamondTrap.takeDamage(20);
		diamondTrap.beRepaired(30);
		diamondTrap.takeDamage(100);
		diamondTrap.attack("you");
	}
	return (0);
}