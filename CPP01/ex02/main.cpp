/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:58:58 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 11:58:58 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "\t****** Memory address ********" << std::endl;
	std::cout << "****** String:\t\t" << &string << std::endl;
	std::cout << "****** Pointer:\t\t" << stringPTR << std::endl;
	std::cout << "****** Reference:\t" << &stringREF << std::endl;

	std::cout << "\n\t********** Value *************" << std::endl;
	std::cout << "****** String:\t\t" << string << std::endl;
	std::cout << "****** Pointer:\t\t" << *stringPTR << std::endl;
	std::cout << "****** Reference:\t" << stringREF << std::endl;
	return (0);
}