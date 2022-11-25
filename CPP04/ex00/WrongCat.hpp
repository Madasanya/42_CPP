/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:41:17 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/22 14:41:17 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{

public:
	WrongCat();
	WrongCat(const WrongCat& obj);
	~WrongCat();
	WrongCat& operator=(const WrongCat& rhs);
	void makeSound() const;

};