/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:28:07 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/02 02:28:07 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion()
{
	if (COMMENT_CANONICAL)
		std::cout << "Conversion default constructor called" << std::endl;
}

Conversion::Conversion(const Conversion& obj)
{
	if (COMMENT_CANONICAL)
		std::cout << "Conversion copy constructor called" << std::endl;
	*this = obj;
}

Conversion& Conversion::operator=(const Conversion& rhs)
{
	if (COMMENT_CANONICAL)
		std::cout << "Conversion copy assignment operator called" << std::endl;
	if (this != &rhs)
		return (*this);
	return (*this);
}

Conversion::Conversion(std::string& input)
	:input_(input), char_value_(0), int_value_(0), float_value_(0), double_value_(0), mode_(handleInput(input))
{
	if (COMMENT_CONSTRUCTOR)
		std::cout << "Conversion parametric constructor called" << std::endl;
	fillAttributes();
}

int Conversion::handleInput (std::string& input) const
{
	const char * ptr;
	char * endptr;
	double strtod_value;

	if (!(input.empty()) && (input[input.length() -1] == 'f' && input.length() > 1 && !(input[input.length() -3] == 'i')))
		if (!(input.length() == 2 && !std::isdigit(input[0])))
			input.resize(input.size() - 1);
	if (input.length() == 1 && std::isprint(input[0]) && !(std::isdigit(input[0])))
		return (CONVERSION_CHAR);
	else
	{
		ptr = input.c_str();
		strtod_value = std::strtod(ptr, &endptr);
		if (ptr == endptr) //detects empty string
		{
			throw std::invalid_argument("");
		}
		while (*endptr != '\0') //detects other invalid input
		{
			if (std::isspace(*endptr) == 0)
			{
				throw std::invalid_argument("");
			}
			++endptr;
		}
		if (errno == ERANGE || //handle overflows
			strtod_value < (inf_ *-1) ||
			strtod_value > inf_)
		{
			throw std::out_of_range("");
		}
		if (isnan(strtod_value) || isinf(strtod_value))
			return(CONVERSION_SCIENCE);
		return (CONVERSION_NUMBER);
	}
	return (0);
}

void Conversion::fillAttributes()
{
	if (COMMENT_FUNCTION)
		std::cout << "Conversion fillAttributes() called" << mode_ << std::endl;
	const char * ptr;
	char * endptr;
	double strtod_value;
	ptr = input_.c_str();
	strtod_value = std::strtod(ptr, &endptr);
	switch (mode_)
	{
		case (CONVERSION_CHAR):
		{
			char_value_ = static_cast<char>(input_[0]);
			int_value_ = static_cast<char>(input_[0]);
			float_value_ = static_cast<float>(input_[0]);
			double_value_ = static_cast<double>(input_[0]);
			break;
		}
		case (CONVERSION_SCIENCE):
		{
			float_value_ = static_cast<float>(strtod_value);
			double_value_ = static_cast<double>(strtod_value);
			break;
		}
		case (CONVERSION_NUMBER):
		{
			if (strtod_value > 31 && strtod_value < 127)
				char_value_ = static_cast<char>(strtod_value);
			if (!(strtod_value > std::numeric_limits<int>::max()) && !(strtod_value < std::numeric_limits<int>::min()))
				int_value_ = static_cast<int>(strtod_value);
			if (!(strtod_value > std::numeric_limits<float>::max()))
				float_value_ = static_cast<float>(strtod_value);
			double_value_ = static_cast<double>(strtod_value);
			break;
		}
	}
}

Conversion::~Conversion()
{
	if (COMMENT_CANONICAL)
		std::cout << "Conversion destructor called" << std::endl;
}

const std::string& Conversion::getInput() const {return (this->input_);}
const char& Conversion::getChar() const {return (this->char_value_);}
const int& Conversion::getInt() const {return (this->int_value_);}
const float& Conversion::getFloat() const {return (this->float_value_);}
const double& Conversion::getDouble() const {return (this->double_value_);}
const int& Conversion::getMode() const {return (this->mode_);}

const double Conversion::inf_ = std::numeric_limits<double>::infinity();
const double Conversion::nan_ = std::numeric_limits<double>::signaling_NaN();

std::ostream& operator<<(std::ostream& ofs, const Conversion& rhs)
{
	switch(rhs.getMode())
	{
		case (CONVERSION_CHAR):
		{
			ofs << "Char: '" << rhs.getChar() << "'" << std::endl;
			ofs << "Int: " << rhs.getInt() << std::endl;
			ofs << std::fixed << std::setprecision(1);
			ofs << "Float: " << rhs.getFloat() << "f" << std::endl;
			break;
		}
		case(CONVERSION_SCIENCE):
		{
			ofs << "Char: " << "impossible" << std::endl;
			ofs << "Int: " << "impossible" << std::endl;
			ofs << std::fixed << std::setprecision(1);
			ofs << "Float: " << rhs.getFloat() << "f" << std::endl;
			break;
		}
		case(CONVERSION_NUMBER):
		{
			if (rhs.getDouble() > 31 && rhs.getDouble() < 127)
				ofs << "Char: '" << rhs.getChar() << "'"<< std::endl;
			else
				ofs << "Char: " << "Non displayable" << std::endl;
			if (rhs.getDouble() > std::numeric_limits<int>::max() || rhs.getDouble() < std::numeric_limits<int>::min())
				ofs << "Int: " <<"Out of int range" << std::endl;
			else
				ofs << "Int: " << rhs.getInt() << std::endl;
			if (rhs.getFloat() == 0 && rhs.getDouble() != 0)
				ofs << "Float: " <<"Out of float range" << std::endl;
			else
			{
				ofs << std::fixed << std::setprecision(1);
				ofs << "Float: " << rhs.getFloat() << "f" << std::endl;
			}
			break;
		}
	} 
	ofs << std::fixed << std::setprecision(1);
	ofs << "Double: " << rhs.getDouble();
	return (ofs);
}