/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:33:24 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/29 04:10:43 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& obj);

public:
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	RobotomyRequestForm(const std::string& target);
	void execute(const Bureaucrat& executor) const;
	void action() const;
};