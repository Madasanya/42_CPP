/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 01:26:53 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/03 01:26:53 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

#define COLOR_BLUE "\033[1;94;49m"
#define COLOR_DEFAULT "\033[0m"

uintptr_t serialize(Data *ptr)
{
	std::cout << "serialize() called" << std::endl;
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	std::cout << "deserialize() called" << std::endl;
	return(reinterpret_cast<Data*>(raw));
}

int main() {
	Data *data = new Data;
	uintptr_t raw;

	data->str_value = "Hello World";
	data->int_value = 23;
	data->float_value = 21.543f;
	data->double_value = 234.23434;

	std::cout << std::endl << COLOR_BLUE << "*** Original Data" << COLOR_DEFAULT << std::endl;

	std::cout << "str_value:\t" << data->str_value << std::endl;
	std::cout << "int_value:\t" << data->int_value << std::endl;
	std::cout << "float_value:\t" << data->float_value << std::endl;
	std::cout << "double_value:\t" << data->double_value << std::endl << std::endl;

	std::cout << std::endl << COLOR_BLUE << "Start Test : " << COLOR_DEFAULT << std::endl;
	raw = serialize(data);
	std::cout << "raw value as uintptr_t:\t\t" << raw << std::endl;
	data = NULL;
	std::cout << "Data after setting to NULL:\t" << data << std::endl; //values are not accessible anymore
	data = deserialize(raw);

	std::cout << std::endl << COLOR_BLUE << "*** Data after cast and recast" << COLOR_DEFAULT << std::endl;

	std::cout << "str_value:\t" << data->str_value << std::endl;
	std::cout << "int_value:\t" << data->int_value << std::endl;
	std::cout << "float_value:\t" << data->float_value << std::endl;
	std::cout << "double_value:\t" << data->double_value << std::endl;

	delete(data);
}