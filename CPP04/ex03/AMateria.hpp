/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:02:49 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/23 16:02:49 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ICharacter;

#define COMMENT_CANONICAL 1

#define COLOR_GREEN "\033[38;5;112m"
#define COLOR_BLUE "\033[1;94;49m"
#define COLOR_GREY "\033[1;90;49m"
#define COLOR_DEFAULT "\033[0m"
#define COLOR_PINK "\033[38;5;200m"
#define COLOR_PURPLE "\033[38;5;135m"
#define COLOR_YELLOW "\033[38;5;220m"

class AMateria
{
protected:
	std::string type_;
public:
	AMateria();
	AMateria(const AMateria& obj);
	virtual ~AMateria();
	AMateria& operator=(const AMateria& rhs);

	AMateria(const std::string& type);

	const std::string& getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
};
