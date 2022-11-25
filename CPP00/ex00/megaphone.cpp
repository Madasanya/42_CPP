/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 03:50:07 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/01 03:50:07 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			for (int j = 0; argv[i][j] != '\0'; j++)
				std::cout << (char)std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}