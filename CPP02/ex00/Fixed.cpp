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
	if (COMMENTS)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	if (COMMENTS)
		std::cout << "Copy constructor called" << std::endl;
	(*this) = obj;
}

Fixed::~Fixed()
{
	if (COMMENTS)
		std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	if (COMMENTS)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->rawValue_ = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	if (COMMENTS)
		std::cout << "getRawBits member function called" << std::endl;
	return(this->rawValue_);
}

void Fixed::setRawBits(const int raw)
{
	if (COMMENTS)
		std::cout << "setRawBits member function called" << std::endl;
	this->rawValue_ = raw;
}

const int Fixed::fracBits_ = 8;