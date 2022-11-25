/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:11:48 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/23 19:11:48 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
private:

public:
	Ice();
	Ice(const Ice& obj);
	~Ice();
	Ice& operator=(const Ice& rhs);

	AMateria* clone() const;
	void use(ICharacter& target);

};