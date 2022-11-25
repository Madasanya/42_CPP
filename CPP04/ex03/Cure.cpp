/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:01:32 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/23 20:01:32 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "Cure"  << COLOR_DEFAULT << " constructor called" << std::endl;
	type_ = "cure";
}

Cure::Cure(const Cure& obj):AMateria()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "Cure"  << COLOR_DEFAULT << " copy constructor called" << std::endl;
	type_ = obj.type_;
}

Cure::~Cure()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "Cure"  << COLOR_DEFAULT << " destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_GREEN << "Cure"  << COLOR_DEFAULT << " copy assignement operator called" << std::endl;
	type_ = rhs.type_;
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria* clone = new Cure();
	return(clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* " << COLOR_GREEN << "heals"  << COLOR_DEFAULT << " " << target.getName() << "'s wounds *" << std::endl;
}
