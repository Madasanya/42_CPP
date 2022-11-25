/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:16:51 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/20 14:16:51 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

#define COMMENTS_CANONICAL 1
#define COMMENTS_CONSTRUCT 1
#define COMMENTS_FUNCTION 0

class Fixed
{
private:
	int rawValue_;
	static const int fracBits_;

public:
	Fixed();
	Fixed(const Fixed& obj);
	~Fixed();
	Fixed& operator=(const Fixed &obj);

	Fixed(const int i2fx);
	Fixed(const float f2fx);

	int getRawBits() const;
	void setRawBits(const int raw);
	float toFloat() const;
	int toInt() const;
	
};

std::ostream& operator<<(std::ostream& ofs, const Fixed& rhs);