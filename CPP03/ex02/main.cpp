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
#include "FragTrap.hpp"


int	main(void)
{
	{
		std::cout <<  COLOR_BLUE << "*** Basic Tests and Gate Guard ***" << COLOR_DEFAULT << std::endl;
		ClapTrap	clapTrap("Clappy");
		FragTrap	fragTrap;

		fragTrap.attack("Jack");
		clapTrap.attack("Sereena");
		fragTrap.highFivesGuys();
		fragTrap.takeDamage(30);
		fragTrap.beRepaired(10);
		fragTrap.takeDamage(50);
		fragTrap.takeDamage(40);
		fragTrap.takeDamage(10);
		fragTrap.beRepaired(1);
		fragTrap.attack(clapTrap.getName());
		clapTrap.beRepaired(5);
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Copying ***" << COLOR_DEFAULT << std::endl;
		FragTrap	fragTrap;

		fragTrap.takeDamage(30);
		FragTrap	frag2 ("FragTrapCopy");
		frag2 = fragTrap;
		frag2.attack(fragTrap.getName());
		fragTrap.takeDamage(frag2.getAttackDamage());
		FragTrap	frag3(fragTrap);
	}
	{

		std::cout << std::endl << COLOR_BLUE << "*** Repair and attack limits ***" << COLOR_DEFAULT << std::endl;
		FragTrap	fragTrap;

		for (int i = 0; i < 50; i++)
			fragTrap.attack("Jack");
		fragTrap.beRepaired(10);
		fragTrap.attack("Jack");
		fragTrap.takeDamage(100);
		fragTrap.takeDamage(100);
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** FragTrap ***" << COLOR_DEFAULT << std::endl;
		FragTrap	fragTrap;
		ScavTrap	scavTrap;

		scavTrap.attack("Jack");
		scavTrap.guardGate();
		fragTrap.attack("Jack");
		fragTrap.highFivesGuys();
		fragTrap.takeDamage(50);
		fragTrap.beRepaired(30);
		fragTrap.takeDamage(80);
	}
	return (0);
}