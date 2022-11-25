/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:40:44 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/22 14:40:44 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("WrongAnimal")
{
	if (COMMENTS_CANONICAL)
		std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	this->type = obj.type;
	if (COMMENTS_CANONICAL)
		std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	if (COMMENTS_CANONICAL)
		std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (COMMENTS_CANONICAL)
		std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "[ Silence ]" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}
