/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 01:41:18 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/02 01:41:18 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <exception>
#include <stdlib.h>
#include <stdexcept>
#include <cerrno>
#include <iomanip>

#define COMMENT_CANONICAL 0
#define COMMENT_CONSTRUCTOR 0
#define COMMENT_FUNCTION 0

#define COLOR_GREEN "\033[38;5;112m"
#define COLOR_BLUE "\033[1;94;49m"
#define COLOR_GREY "\033[1;90;49m"
#define COLOR_DEFAULT "\033[0m"
#define COLOR_PINK "\033[38;5;200m"
#define COLOR_PURPLE "\033[38;5;135m"
#define COLOR_YELLOW "\033[38;5;220m"
#define COLOR_RED "\033[38;5;196m"

#define CONVERSION_CHAR 0
#define CONVERSION_SCIENCE 1
#define CONVERSION_NUMBER 2

class Conversion
{
private:
	Conversion();
	Conversion(const Conversion& obj);
	Conversion& operator=(const Conversion& rhs);
	std::string input_;
	char char_value_;
	int int_value_;
	float float_value_;
	double double_value_;
	int mode_;
	static const double inf_;
	static const double nan_;
	int handleInput (std::string& input) const;
	void fillAttributes();

public:
	~Conversion();
	Conversion(std::string& input);
	const std::string& getInput() const;
	const char& getChar() const;
	const int& getInt() const;
	const float& getFloat() const;
	const double& getDouble() const;
	const int& getMode() const;
};

std::ostream& operator<<(std::ostream& ofs, const Conversion& rhs);