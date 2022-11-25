/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 04:46:21 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/05 06:17:07 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(const Span& obj):vec_(obj.vec_)
{
	this->maxLength  = obj.maxLength;
}

Span::~Span() {}

Span& Span::operator=(const Span& rhs)
{
	if (this == &rhs)
		return(*this);
	this->vec_ = rhs.vec_;
	this->maxLength = rhs.maxLength;
	return (*this);
}

Span::Span(unsigned int N)
{
	maxLength = N;
}

void Span::addNumber(int newNumber)
{
	try
	{
		if (static_cast<int>(vec_.size()) < maxLength)
			vec_.push_back(newNumber);
		else
			throw(std::exception());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": End of array size rached.\n";
	}
}

void Span::massFill()
{
	srand(time(NULL));
	int oldSize = vec_.size();
	vec_.resize(maxLength);
	std::generate(vec_.begin() + oldSize, vec_.end(), randomNumber);
}

int Span::shortestSpan()
{
	try
	{
		if (vec_.size() < 2)
			throw(std::exception());
		std::vector<int> vecCopy = vec_;
		std::sort(vecCopy.begin(), vecCopy.end());
		std::adjacent_difference(vecCopy.begin(), vecCopy.end(), vecCopy.begin());
		return(*(std::min_element(vecCopy.begin(), vecCopy.end())));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": Not enough values to calculate shortes span. Value is therefore: ";
		return (0);
	}

}

int Span::longestSpan()
{	
	try
	{
		if (vec_.size() < 2)
			throw(std::exception());
		return(*(std::max_element(vec_.begin(), vec_.end())) - *(std::min_element(vec_.begin(), vec_.end())));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": Not enough values to calculate longest span. Value is therefore: ";
		return (0);
	}
}

std::vector<int> Span::getVector(void) const
{
	return (vec_);
}

int randomNumber()
{
	int i = rand() % 100;
	return(i);
}

std::ostream& operator<<(std::ostream& ofs, const Span& rhs)
{
	for (int i = 0; i  < static_cast<int>(rhs.getVector().size()); i++)
		ofs << "[ " << rhs.getVector()[i] << " ]";
	ofs << std::endl;
	return(ofs);
}