/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:18:02 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 19:18:02 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static	std::string strToUpper(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = (char)std::toupper(str[i]);
	return (str);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	Harl harl;
	harl.complain("DEBUG", strToUpper(argv[1]));
	harl.complain("INFO", strToUpper(argv[1]));
	harl.complain("WARNING", strToUpper(argv[1]));
	harl.complain("ERROR", strToUpper(argv[1]));
	harl.complain("test", strToUpper(argv[1]));
}