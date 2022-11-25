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

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout <<  COLOR_BLUE << "*** Memory Test ***" << COLOR_DEFAULT << std::endl;
		const Dog* j = new Dog();
		const Cat* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout <<  COLOR_BLUE << "*** Deep Copy I ***" << COLOR_DEFAULT << std::endl;

		const Dog* rex = new Dog();

		std::cout << std::endl;
		rex->getBrain()->setIdea((unsigned int)3, "Bones...");
		std::cout << "Rex is thinking of: [ " << rex->getBrain()->getIdea(3) << " ]" << std::endl;
		std::cout << std::endl;

		const Dog* caesar = new Dog();
		*((Dog *)caesar) = *((Dog *)rex);

		std::cout << std::endl;
		rex->getBrain()->setIdea((unsigned int)3, "Butterflies...");
		std::cout << "Caesar is thinking of: [ "  << caesar->getBrain()->getIdea(3) << " ]" << std::endl;
		std::cout << "Rex is thinking of: [ "  << rex->getBrain()->getIdea(3) << " ]" << std::endl;
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