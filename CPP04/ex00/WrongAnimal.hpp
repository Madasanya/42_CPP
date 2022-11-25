/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:40:33 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/22 14:40:33 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define COMMENTS_CANONICAL 1

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& obj);
	virtual ~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& rhs);
	
	void makeSound() const;
	std::string getType() const;

};