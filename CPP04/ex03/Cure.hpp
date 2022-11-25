/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:00:53 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/23 20:00:53 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
private:

public:
	Cure();
	Cure(const Cure& obj);
	~Cure();
	Cure& operator=(const Cure& rhs);

	AMateria* clone() const;
	void use(ICharacter& target);

};