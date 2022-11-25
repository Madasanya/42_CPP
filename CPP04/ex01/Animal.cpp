/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:21:57 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/22 12:21:57 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():type("Animal")
{
	if (COMMENTS_CANONICAL)
		std::cout << COLOR_GREEN << "Animal" << COLOR_DEFAULT << " default constructor called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	this->type = obj.type;
	if (COMMENTS_CANONICAL)
		std::cout << COLOR_GREEN <<  "Animal" << COLOR_DEFAULT << " copy constructor called" << std::endl;
}

Animal::~Animal()
{
	if (COMMENTS_CANONICAL)
		std::cout << COLOR_GREEN <<  "Animal" << COLOR_DEFAULT << " destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	if (COMMENTS_CANONICAL)
		std::cout << COLOR_GREEN <<  "Animal" << COLOR_DEFAULT << "copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << COLOR_GREY <<  "[ Silence ]" << COLOR_DEFAULT << std::endl;
}

const std::string& Animal::getType() const
{
	return (type);
}
