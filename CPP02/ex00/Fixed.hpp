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

#define COMMENTS 1

class Fixed
{
private:
	int rawValue_;
	static const int fracBits_;

public:
	Fixed();
	Fixed(const Fixed& obj);
	~Fixed();
	Fixed& operator=(const Fixed& rhs);

	int getRawBits() const;
	void setRawBits(const int raw);
};
