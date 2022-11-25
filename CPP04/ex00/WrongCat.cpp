/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:41:05 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/22 14:41:05 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	if (COMMENTS_CANONICAL)
		std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj):WrongAnimal()
{
	this->type = obj.type;
	if (COMMENTS_CANONICAL)
		std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	if (COMMENTS_CANONICAL)
		std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	if (COMMENTS_CANONICAL)
		std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Meow, Meow" << std::endl;
}
