/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:21:13 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/23 19:21:13 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_BLUE <<"Ice" << COLOR_DEFAULT << " constructor called" << std::endl;
	type_ = "ice";
}

Ice::Ice(const Ice& obj):AMateria()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_BLUE << "Ice" << COLOR_DEFAULT << " copy constructor called" << std::endl;
	type_ = obj.type_;
}

Ice::~Ice()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_BLUE << "Ice" << COLOR_DEFAULT << " destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_BLUE << "Ice" << COLOR_DEFAULT << " copy assignement operator called" << std::endl;
	type_ = rhs.type_;
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria* clone = new Ice();
	return(clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an "  << COLOR_BLUE  << "ice bolt"  << COLOR_DEFAULT << " at " << target.getName() << " *" << std::endl;
}
