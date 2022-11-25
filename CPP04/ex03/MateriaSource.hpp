/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:41:54 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/24 00:41:54 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
# include "AMateria.hpp" //optional?

class MateriaSource: public IMateriaSource
{
private:
	int counter_;
	AMateria* materia_[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& obj);
	~MateriaSource();
	MateriaSource& operator=(const MateriaSource& rhs);
	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);
	AMateria* getMateria(const int& idx) const; //optional for testing


};