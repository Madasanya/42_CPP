/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:58:57 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/07 00:58:57 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#define EXIT_ON_FAILURE 1
#define EXIT_ON_SUCCESS 0


static int inputCheck (int argc, char ** argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (EXIT_ON_FAILURE);
	}
	if (argv[2] == (std::string)"")
	{
		std::cout << "Argument corrupted" << std::endl;
		return (EXIT_ON_FAILURE);
	}
	return (EXIT_ON_SUCCESS);
}

static void replace(char** argv, std::ifstream& ifs, std::ofstream& ofs)
{
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	size_t pos;
	std::string str;
	while (getline(ifs, str))
	{
		pos = str.find(s1);
		while (pos != std::string::npos)
		{
			str.erase(pos, s1.length());
			str.insert(pos, s2);
			pos = str.find(s1);
		}
		ofs << str;
		if(!ifs.eof())
			ofs << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (inputCheck(argc, argv))
		return(EXIT_ON_FAILURE);
	std::string infile = argv[1];
	std::ifstream ifs;
	ifs.open(infile.c_str());
	if (!(ifs.is_open()))
	{
		std::cout << "Inputfile could not be opened!" << std::endl;
		return (EXIT_ON_FAILURE);
	}
	std::string outfile;
	outfile = infile + ".replace";
	std::ofstream ofs(outfile.c_str());
	replace(argv, ifs, ofs);
	ifs.close();
	ofs.close();
}