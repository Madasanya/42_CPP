/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:40:17 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/22 12:40:17 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	if (COMMENTS_CANONICAL)
		std::cout << COLOR_PURPLE << "Dog" << COLOR_DEFAULT << " default constructor called" << std::endl;
}

Dog::Dog(const Dog& obj):Animal()
{
	this->type = obj.type;
	if (COMMENTS_CANONICAL)
		std::cout << COLOR_PURPLE << "Dog" << COLOR_DEFAULT << " copy constructor called" << std::endl;
}

Dog::~Dog()
{
	if (COMMENTS_CANONICAL)
		std::cout << COLOR_PURPLE << "Dog" << COLOR_DEFAULT << " destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (COMMENTS_CANONICAL)
		std::cout << COLOR_PURPLE << "Dog" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void Dog::makeSound() const 
{
	std::cout << COLOR_GREY << "Woof, Woof" << COLOR_DEFAULT << std::endl;
}
