/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:34:36 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/24 01:34:36 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_YELLOW << "MateriaSource" << COLOR_DEFAULT << " constructor called" << std::endl;
	counter_ = 0;
	for(int i = 0; i < 4; i++)
		materia_[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_YELLOW << "MateriaSource" << COLOR_DEFAULT << " copy constructor called" << std::endl;
	counter_ = obj.counter_;
	for(int i = 0; i < counter_; i++)
		materia_[i] = obj.materia_[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < counter_; i++)
	{
		if (materia_[i] != NULL)
			delete (materia_[i]);
		materia_[i] = NULL;
	}
	if (COMMENT_CANONICAL)
		std::cout << COLOR_YELLOW << "MateriaSource" << COLOR_DEFAULT << " destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << COLOR_YELLOW << "MateriaSource" << COLOR_DEFAULT << " copy assignment operator called" << std::endl;
	for(int i = 0; i < counter_; i++)
		delete (materia_[i]);
	counter_ = rhs.counter_;
	for(int i = 0; i < counter_; i++)
		materia_[i] = rhs.materia_[i]->clone();
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (counter_ > 3)
	{
		std::cout << "MateriaSource is already full. Please find onother source to store more materias" << std::endl;
		return;
	}
	materia_[counter_] = materia;
	counter_++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while(i < counter_ + 1)
	{
		if (!materia_[i]->getType().compare(type))
		{
			break;
		}
		if (i == 3)
			return (0);
		i++;
	}
	return (materia_[i]->clone());
}

AMateria* MateriaSource::getMateria(const int& idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (materia_[idx]);
}
