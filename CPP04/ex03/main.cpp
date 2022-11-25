/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:46:17 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/23 19:46:17 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
 	{
		std::cout <<  COLOR_BLUE << "*** Materia Copy and use() Test ***" << COLOR_DEFAULT << std::endl;
		std::cout <<  COLOR_BLUE << "***\t use()***" << COLOR_DEFAULT << std::endl;
		AMateria* ice = new Ice();
		std::cout << ice->getType() << std::endl;
		Character target;
		ice->use(target);

		std::cout <<  COLOR_BLUE << "***\t wrong type***" << COLOR_DEFAULT << std::endl;
		AMateria* cure = new Cure();
		*cure = *ice;
		std::cout << cure->getType() << std::endl;
		cure->use(target);

		std::cout <<  COLOR_BLUE << "***\t cpy type***" << COLOR_DEFAULT << std::endl;
		AMateria* cpy = ice->clone();
		std::cout << cpy->getType() << std::endl;
		cpy->use(target);

		delete(ice);
		delete(cure);
		delete(cpy);
	}
	{
		std::cout << std::endl <<  COLOR_BLUE << "*** Example Subject Sheet ***" << COLOR_DEFAULT << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl <<  COLOR_BLUE << "*** Full Test ***" << COLOR_DEFAULT << std::endl;
		std::cout <<  COLOR_BLUE << "***\t Init Character, MateriaSource and fill inventory ***" << COLOR_DEFAULT << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character ("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->equip(src->createMateria("cure"));
		ICharacter* bob = new Character();
		std::cout <<  COLOR_BLUE << "***\t Character use() ***" << COLOR_DEFAULT << std::endl;
		me->use(0, *bob);
		std::cout <<  COLOR_BLUE << "***\t unequip() and deep copy Character ***" << COLOR_DEFAULT << std::endl;
		me->unequip(2);
		me->unequip(0);
		*((Character *)me) = *((Character *)bob); //also deletes old equipment
		me->equip(src->createMateria("cure"));
		me->equip(src->createMateria("cure"));
		me->unequip(0);
		me->use(1, *bob);
		bob->equip(src->createMateria("ice"));
		bob->use(0, *me);
		std::cout <<  COLOR_BLUE << "***\t Destructor ***" << COLOR_DEFAULT << std::endl;
		delete bob;
		delete me;
		delete src;
		return 0;
	}
}