/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 04:43:00 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/05 06:17:34 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#define COLOR_BLUE "\033[1;94;49m"
#define COLOR_DEFAULT "\033[0m"

#include <list>


int main()
{
	{
		std::cout << std::endl << COLOR_BLUE << "*** Example Subject Sheet ***" << COLOR_DEFAULT << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		std::cout << mstack.top() << std::endl;
		//[...]
		mstack.push(0);
		std::cout << mstack.top() << std::endl;
		std::cout << "*** Iterator ***" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** List Example Subject Sheet ***" << COLOR_DEFAULT << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		std::cout << mstack.back() << std::endl;
		//[...]
		mstack.push_back(0);
		std::cout << mstack.back() << std::endl;
		std::cout << "*** Iterator ***" << std::endl;
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** Reverse Iterator ***" << COLOR_DEFAULT << std::endl;
		MutantStack<int> rev_it;
		rev_it.push(1);
		rev_it.push(2);
		rev_it.push(3);
		rev_it.push(4);
		rev_it.push(5);
		rev_it.push(6);
		for (MutantStack<int>::reverse_iterator it = rev_it.rbegin(); it != rev_it.rend(); it++)
		{
			std::cout << *it;
		}
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << COLOR_BLUE << "*** List Reverse Iterator ***" << COLOR_DEFAULT << std::endl;
		std::list<int> rev_it;
		rev_it.push_back(1);
		rev_it.push_back(2);
		rev_it.push_back(3);
		rev_it.push_back(4);
		rev_it.push_back(5);
		rev_it.push_back(6);
		for (std::list<int>::reverse_iterator it = rev_it.rbegin(); it != rev_it.rend(); it++)
		{
			std::cout << *it;
		}
		std::cout << std::endl;
	}
	return 0;
}