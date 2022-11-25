/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 02:53:40 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/04 03:34:03 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename T>
void iter(T *address, unsigned int size, void (*f)(const T& elem))
{
	for (unsigned int i = 0; i  < size; i++)
	{
		(*f)(address[i]);
	} 
}

template<typename T>
void print(const T& elem)
{
	std::cout << "elem: " << elem << std::endl;
}