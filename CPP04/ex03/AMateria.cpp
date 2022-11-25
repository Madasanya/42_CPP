/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:28:08 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/23 16:28:08 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PURPLE << "AMateria" << COLOR_DEFAULT << " constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PURPLE << "AMateria" << COLOR_DEFAULT << " copy constructor called" << std::endl;
	type_ = obj.type_;
}

AMateria::~AMateria()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PURPLE << "AMateria" << COLOR_DEFAULT << " destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PURPLE << "AMateria" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
	if (!type_.compare(rhs.type_))
	{
		type_ = rhs.type_;
	}
	else
	{
		std::cout << "Incompatible Materia type. Assignment failed." << std::endl;;
	}
	return (*this);
}


AMateria::AMateria(const std::string& type)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PURPLE << "AMateria parametric constructor called" << std::endl;
	type_ = type;
}


const std::string& AMateria::getType() const //Returns the materia type
{
	return(type_);
}
