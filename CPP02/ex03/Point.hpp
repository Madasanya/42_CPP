/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:49:12 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/20 23:01:04 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x_;
		const Fixed y_;

	public:
		Point();
		Point(const Point& obj);
		Point& operator=(const Point& obj);
		~Point();

		Point(const float x, const float y);
		Point(const int x, const int y);

		Fixed getX(void) const;
		Fixed getY(void) const;
};

std::ostream& operator<<(std::ostream& ofs, const Point& p);