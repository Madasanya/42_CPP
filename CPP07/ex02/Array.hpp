/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:57:05 by mamuller          #+#    #+#             */
/*   Updated: 2022/05/04 16:57:05 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <exception>
#include <time.h>

template<typename T>
class Array
{
	public:
		Array<T>(): arrayPtr(new T[0]), size_(0) {};
		Array<T>(unsigned int n): arrayPtr(new T[n]), size_(n) {};
		~Array<T>() {delete[] arrayPtr;};
		Array<T>(const Array<T>& obj):arrayPtr(new T[obj.size_]), size_(obj.size_)
		{
			for (std::size_t i = 0; i < size_; i++)
				this->arrayPtr[i] = obj.arrayPtr[i];
		};
		Array<T>& operator=(const Array<T>& rhs)
		{
			if (this == &rhs)
				return (*this);
			this->size_ = rhs.size_;
			if (arrayPtr != NULL)
				delete[]this->arrayPtr;
			arrayPtr = NULL;
			this->arrayPtr = new T[rhs.size_];
			for (std::size_t i = 0; i < size_; i++)
				this->arrayPtr[i] = rhs.arrayPtr[i];
			return (*this);
		};
		T& operator[](std::size_t idx)
		{
			if (idx < 0 || idx >= size_)
				throw(std::exception());
			return (arrayPtr[idx]);
		};
		std::size_t size() {return (size_);};
		T* arrayPtr;
	private:
		std::size_t size_;
};