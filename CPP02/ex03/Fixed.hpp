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

#define COMMENTS_CANONICAL 0
#define COMMENTS_CONSTRUCT 0
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

	//comparison operator
	bool operator>(const Fixed& rhs) const;
	bool operator<(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;

	//arithmetic operator
	Fixed operator+(const Fixed& rhs) const;
	Fixed operator-(const Fixed& rhs) const;
	Fixed operator*(const Fixed& rhs) const;
	Fixed operator/(const Fixed& rhs) const;

	//increment/decrement operator
	Fixed operator++(int);
	Fixed& operator++(void);
	Fixed operator--(int);
	Fixed& operator--(void);

	static Fixed& min(Fixed& obj1, Fixed& obj2);
	static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
	static Fixed& max(Fixed& obj1, Fixed& obj2);
	static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
};

std::ostream& operator<<(std::ostream& ofs, const Fixed& rhs);