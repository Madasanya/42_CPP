/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:47:49 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/20 23:01:09 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//	CONSTRUCTORS | DESTRUCTOR

Point::Point():x_(0), y_(0)
{
	if (COMMENTS_CANONICAL)
		std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const Point &obj):x_(obj.x_), y_(obj.y_)
{
	if (COMMENTS_CANONICAL)
		std::cout << "Point copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& obj)
{
	if (COMMENTS_CANONICAL)
		std::cout << "Point copy assignment operator called" << std::endl;
	const_cast<Fixed &>(this->x_) = obj.x_;
	const_cast<Fixed &>(this->y_) = obj.y_;
	return (*this);
}

Point::~Point()
{
	if (COMMENTS_CANONICAL)
		std::cout << "Point destructor called" << std::endl;
}

//	MEMBER FUNCTIONS

Point::Point(const float x, const float y):x_(x), y_(y)
{
	if (COMMENTS_CONSTRUCT)
		std::cout << "Point parametric constructor called" << std::endl;
}

Point::Point(const int x, const int y):x_(x), y_(y)
{
	if (COMMENTS_CONSTRUCT)
		std::cout << "Point parametric constructor called" << std::endl;
}

Fixed Point::getX(void) const
{
	if (COMMENTS_FUNCTION)
		std::cout << "Point::getX member function called" << std::endl;
	return (this->x_);
}

Fixed Point::getY(void) const
{
	if (COMMENTS_FUNCTION)
		std::cout << "Point::getY member function called" << std::endl;
	return (this->y_);
}

std::ostream& operator<<(std::ostream& ofs, const Point& p)
{
	if (COMMENTS_FUNCTION)
		std::cout << "Point << assignment operator called" << std::endl;
	ofs << "(" << p.getX().toFloat() << " , " << p.getY().toFloat() << ")";
	return (ofs);
}

