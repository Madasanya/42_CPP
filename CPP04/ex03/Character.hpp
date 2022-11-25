/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:00:02 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/24 12:00:02 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "MateriaSource.hpp"

class Character: public ICharacter
{
private:
	static const int inventorySize = 4;
	std::string name_;
	AMateria* inventory_[inventorySize];
	bool inventoryUsage_[inventorySize];
	AMateria** unequipedMaterias_;
	int unequipCounter_;
public:
	Character();
	Character(const Character& obj);
	~Character();
	Character& operator=(const Character& rhs);

	Character(const std::string& name);

	const std::string& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	AMateria** getUnequiped() const;
};