/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
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

class Cat: public Animal
{

public:
	Cat();
	Cat(const Cat& obj);
	~Cat();
	Cat& operator=(const Cat& rhs);
	void makeSound() const;

};