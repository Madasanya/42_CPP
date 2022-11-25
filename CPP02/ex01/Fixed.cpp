/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:29:41 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/20 14:29:41 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():rawValue_(0)
{
	if (COMMENTS_CANONICAL)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	if (COMMENTS_CANONICAL)
		std::cout << "Copy constructor called" << std::endl;
	(*this) = obj;
}

Fixed::~Fixed()
{
	if (COMMENTS_CANONICAL)
		std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	if (COMMENTS_CANONICAL)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->rawValue_ = rhs.getRawBits();
	return (*this);
}

Fixed::Fixed(const int i2fx)
{
	if (COMMENTS_CONSTRUCT)
		std::cout << "Int constructor called" << std::endl;
	this->rawValue_ = i2fx << fracBits_;
}

Fixed::Fixed(const float f2fx)
{
	if (COMMENTS_CONSTRUCT)
		std::cout << "Float constructor called" << std::endl;
	this->rawValue_ = roundf(f2fx * (1 << fracBits_));
}

int Fixed::getRawBits() const
{
	if (COMMENTS_FUNCTION)
		std::cout << "getRawBits member function called" << std::endl;
	return(this->rawValue_);
}

void Fixed::setRawBits(const int raw)
{
	if (COMMENTS_FUNCTION)
		std::cout << "setRawBits member function called" << std::endl;
	this->rawValue_ = raw;
}


float Fixed::toFloat() const
{
	if (COMMENTS_FUNCTION)
		std::cout << "toFloat member function called" << std::endl;
	return (float(this->rawValue_) / (1 << fracBits_));
}

int Fixed::toInt() const
{
	if (COMMENTS_FUNCTION)
		std::cout << "toInt member function called" << std::endl;
	return (this->rawValue_ >> fracBits_);
}

std::ostream& operator<<(std::ostream& ofs, const Fixed& rhs)
{
	if (COMMENTS_FUNCTION)
		std::cout << "<< operator function called" << std::endl;
	ofs << rhs.toFloat();
	return (ofs);
}

const int Fixed::fracBits_ = 8;