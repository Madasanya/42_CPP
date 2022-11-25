/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:05:09 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/22 12:05:09 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

#define COMMENTS_CANONICAL 1

#define COLOR_GREEN "\033[38;5;112m"
#define COLOR_BLUE "\033[1;94;49m"
#define COLOR_GREY "\033[1;90;49m"
#define COLOR_DEFAULT "\033[0m"
#define COLOR_PURPLE "\033[38;5;135m"
#define COLOR_YELLOW "\033[38;5;220m"

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal& obj);
	virtual ~Animal();
	Animal& operator=(const Animal& rhs);
	
	virtual void makeSound() const;
	const std::string& getType() const;

};