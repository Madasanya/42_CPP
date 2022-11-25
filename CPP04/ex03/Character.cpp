/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:59:10 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/24 11:59:10 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	:name_("Zardoz"), unequipedMaterias_(NULL), unequipCounter_(0)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PINK << "Character" << COLOR_DEFAULT << " construcotr called" << std::endl;
	for (int i = 0; i < inventorySize; i++)
	{
		inventory_[i] = NULL;
	}
	unequipedMaterias_= new AMateria*[1]();
	unequipedMaterias_[0] = NULL;
}

Character::Character(const Character& obj)
	:ICharacter(), unequipedMaterias_(NULL), unequipCounter_(0)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PINK << "Character" << COLOR_DEFAULT << " copy constructor called" << std::endl;
	name_ = obj.name_;
	for (int i = 0; i < inventorySize; i++)
	{
		inventory_[i] = obj.inventory_[i]->clone();
	}
}

Character::~Character()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PINK << "Character" << COLOR_DEFAULT << " destructor called" << std::endl;
	for (int i = 0; i < inventorySize; i++)
	{
		
		if (inventory_[i] != NULL)
			delete (inventory_[i]);
		inventory_[i] = NULL;
	}
	if (unequipedMaterias_ != NULL)
	{
		for (int i = 0; i < unequipCounter_; i++)
			if (unequipedMaterias_[i] != NULL)
				delete (unequipedMaterias_[i]);
	}
	delete []unequipedMaterias_;
}

Character& Character::operator=(const Character& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PINK << "Character" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
	name_ = rhs.name_;
	for (int i = 0; i < inventorySize; i++)
	{
		if (inventory_[i])
		{
			delete (inventory_[i]);
			inventory_[i] = NULL;
		}
		if (rhs.inventory_[i])
			inventory_[i] = rhs.inventory_[i]->clone();
		else
			inventory_[i] = NULL;
	}
	return(*this);
}


Character::Character(const std::string& name)
	:name_(name), unequipCounter_(0)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_PINK << "Character" << COLOR_DEFAULT << " parametric constructor called" << std::endl;
	for (int i = 0; i < inventorySize; i++)
	{
		inventory_[i] = NULL;
	}
	unequipedMaterias_= new AMateria*[1]();
	unequipedMaterias_[0] = NULL;
}

const std::string& Character::getName() const
{
	return (this->name_);
}

void Character::equip(AMateria* m)
{
	int i = 0;

	for (i = 0; i < inventorySize; i++)
	{
		if (inventory_[i] == NULL)
		{
			inventory_[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full. Please unequip materia or buy an additional inventory slot (coming soon)" << std::endl;
}

void Character::unequip(int idx)
{
if (idx < 0 || idx > 3)
	{
		std::cout << "Your inventory is not a black hole..." << std::endl;
		return;
	}
	else if (inventory_[idx] == NULL)
	{
		std::cout << "Nothing found to unequip here." << std::endl;
		return;
	}
	if (unequipCounter_ == 0)
	{
		this->unequipedMaterias_[0] = this->inventory_[idx];
		this->inventory_[idx] = NULL;
	}
	else
	{
		AMateria** tmp = unequipedMaterias_;
		unequipedMaterias_ = new AMateria*[unequipCounter_ + 1]();
		for (int i = 0; i < unequipCounter_; i++)
			unequipedMaterias_[i] = tmp[i];
		unequipedMaterias_[unequipCounter_] = this->inventory_[idx];
		this->inventory_[idx] = NULL;
		delete [] tmp;
	}
	unequipCounter_++;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "What are you trying to do?!" << std::endl;
		return;
	}
	else if (inventory_[idx] == NULL)
	{
		std::cout << "Nothing found to use here." << std::endl;
		return;
	}
	inventory_[idx]->use(target);
}