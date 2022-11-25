/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:38:50 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/05 21:38:50 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <string>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack(){};
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;

	iterator begin(void) { return this->c.begin(); }
	iterator end(void) { return this->c.end(); }
	reverse_iterator rbegin(void) { return this->c.rbegin(); }
	reverse_iterator rend(void) { return this->c.rend(); }

private:
	MutantStack(const MutantStack & obj) {*this = obj;};
	MutantStack& operator=(const MutantStack& rhs)
	{
		(void)rhs;
		return (*this);
	};
};