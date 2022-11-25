/* ************************************************************************** */
/*																																						*/
/*																												:::			::::::::	 */
/*	 main.cpp																					 :+:			:+:		:+:	 */
/*																										+:+ +:+				 +:+		 */
/*	 By: mamuller <mamuller@student.42wolfsburg>		+#+	+:+			 +#+				*/
/*																								+#+#+#+#+#+	 +#+					 */
/*	 Created: 2022/04/22 12:25:41 by mamuller					#+#		#+#						 */
/*	 Updated: 2022/04/22 12:25:41 by mamuller				 ###	 ########.fr			 */
/*																																						*/
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout <<  COLOR_BLUE << "*** Memory Test ***" << COLOR_DEFAULT << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout <<  COLOR_BLUE << "*** Deep Copy ***" << COLOR_DEFAULT << std::endl;

		const Animal* rex = new Dog();

		std::cout << std::endl;
		((Dog*)rex)->getBrain()->setIdea((unsigned int)3, "Bones...");
		std::cout << "Rex is thinking of: [ " << ((Dog*)rex)->getBrain()->getIdea(3) << " ]" << std::endl;
		std::cout << std::endl;

		const Animal* caesar = new Dog();
		*((Dog *)caesar) = *((Dog *)rex);

		std::cout << std::endl;
		((Dog*)rex)->getBrain()->setIdea((unsigned int)3, "Butterflies...");
		std::cout << "Caesar is thinking of: [ "  << ((Dog*)caesar)->getBrain()->getIdea(3) << " ]" << std::endl;
		std::cout << "Rex is thinking of: [ "  << ((Dog*)rex)->getBrain()->getIdea(3) << " ]" << std::endl;
		std::cout << std::endl;
	
		delete rex;
		delete caesar;
		std::cout << std::endl;
	}
	{
		std::cout <<  COLOR_BLUE << "*** Scope Test ***" << COLOR_DEFAULT << std::endl;
		Cat basic;
		{
			Cat tmp = basic;
		}
	}
}