/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:54:42 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/19 18:54:42 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define FILTER 0
#define IMPORTANT 1
#define IRRELEVANT 2

class Harl
{
private:
	void debug();
	void info();
	void warning();
	void error();

public:
	Harl();
	~Harl();
	void complain(std::string level, std::string filter);
};
