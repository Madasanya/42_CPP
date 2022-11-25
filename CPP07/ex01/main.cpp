/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 02:53:08 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/04 03:38:11 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iomanip>

int main()
{
	char arr1[26];
	int arr2[26];
	float arr3[26];

	for (int i = 0; i < 26; ++i)
	{
		arr1[i] = i + 'a';
		arr2[i] = i;
		arr3[i] = i + 0.5;
	}
	::iter(arr1, 26, print);
	::iter(arr2, 26, print);
	std::cout << std::fixed << std::setprecision(1);
	::iter(arr3, 26, print);
}