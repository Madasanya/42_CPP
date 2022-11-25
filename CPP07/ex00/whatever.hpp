/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 02:50:06 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/04 02:50:45 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#pragma once

template<typename T>
T max(const T& x, const T& y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

template<typename T>
T min(const T& x, const T& y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

template<typename T>
void swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp; 
}