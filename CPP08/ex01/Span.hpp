/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 04:34:51 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/05 06:17:15 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <time.h>

class Span
{
private:
	Span();
	std::vector<int> vec_;

public:
	Span(const Span& obj);
	~Span();
	Span& operator=(const Span& rhs);
	Span(unsigned int N);
	void addNumber(int newNumber);
	void massFill();
	int shortestSpan();
	int longestSpan();
	std::vector<int> getVector(void) const;
	int maxLength;

};

int randomNumber();
std::ostream& operator<<(std::ostream& ofs, const Span& rhs);