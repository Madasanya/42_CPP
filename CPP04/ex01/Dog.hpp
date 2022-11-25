/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:40:07 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/22 12:40:07 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog: public Animal
{

public:
	Dog();
	Dog(const Dog& obj);
	virtual ~Dog();
	Dog& operator=(const Dog& rhs);

	void makeSound() const;
	Brain* getBrain() const;

private:
	Brain* brain;
};