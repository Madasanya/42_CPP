/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 01:08:40 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/05 03:35:53 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <list>
#include <queue>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = find(container.begin(), container.end(), value);
	if (it != container.end())
		return(it);
	else
		throw(std::exception());
}