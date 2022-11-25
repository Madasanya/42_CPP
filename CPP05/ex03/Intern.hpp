/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:22:59 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/29 20:22:59 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& obj);
	Intern& operator=(const Intern& rhs);
	~Intern();
	AForm* makeForm(const std::string& form, const std::string& target);
	
	class FormNotFound: public std::exception
	{
	public:
		const char* what() const throw();
	};

};