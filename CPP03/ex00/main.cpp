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

int	main(void)
{
	{

		std::cout << COLOR_BLUE << "*** Fight & Engergy Test I ***" << COLOR_DEFAULT << std::endl;
		ClapTrap clappy("Clappy");
		ClapTrap trappy("Trappy");

		for (int i = 0; i < 12; i++)
		{
			if (clappy.getEnergyPoints() < 1)
				clappy.attack(trappy.getName());
			else
			{
				clappy.attack(trappy.getName());
				trappy.takeDamage(clappy.getAttackDamage());
			}
		}
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Copy and Accessor Test ***" << COLOR_DEFAULT << std::endl;
		ClapTrap	clapTrap1("Clappy");
		ClapTrap	clapTrap2("Trappy");
		ClapTrap	clapTrap3;
		clapTrap2.takeDamage(5);
		ClapTrap	clapTrap4(clapTrap2);

		clapTrap3 = clapTrap1;
		clapTrap3.setName("Assasin");
		clapTrap3.setAttackDamage(20);

		clapTrap3.attack(clapTrap1.getName());
		clapTrap4.attack("Jack");
	}

	{
		std::cout << std::endl << COLOR_BLUE << "***Hit Points Test ***" << COLOR_DEFAULT << std::endl;
		ClapTrap	clapTrap1("Clappy");
		ClapTrap	clapTrap2("Trappy");
		ClapTrap	clapTrap3;
		ClapTrap	clapTrap4(clapTrap2);

		clapTrap3 = clapTrap1;

		clapTrap3.attack("me");
		clapTrap2.attack("Jack");
		clapTrap1.takeDamage(5);
		clapTrap1.takeDamage(3);
		clapTrap1.beRepaired(10);
		clapTrap1.takeDamage(50);
		clapTrap1.beRepaired(100);
		clapTrap1.takeDamage(50);
		clapTrap1.attack("a tree");
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Engergy Test II ***" << COLOR_DEFAULT << std::endl;
		ClapTrap	clapTrap1;

		clapTrap1.attack("Jack");
		clapTrap1.attack("you");
		clapTrap1.attack("me");
		clapTrap1.attack("Jack");
		clapTrap1.attack("Jack");
		clapTrap1.attack("Jack");
		clapTrap1.beRepaired(1);
		clapTrap1.beRepaired(1);
		clapTrap1.beRepaired(1);
		clapTrap1.beRepaired(1);
		clapTrap1.beRepaired(1);
		clapTrap1.attack("Jack");
		clapTrap1.takeDamage(10);
	}
	return (0);
}