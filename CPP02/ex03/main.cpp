/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:12:05 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/20 15:12:05 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point a, Point b, Point c, const Point point);

static std::string	bool2msg(bool b)
{
	if (b)
		return ("Yes, it is!");
	return ("No, it isn't!");
}

int	main(void)
{
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(0, 5);
	Point	p1(1, 1);
	Point	p2(10, 5);

	Point	a2(1,1);
	Point	b2(5,-1);
	Point	c2(3,5);
	Point	p3(2,3);
	Point	p4(3,3);

	Point a3(292,376);
	Point b3(486,141);
	Point c3(94,99);
	Point p5(189.0052080154419f,198.1267318725586f);

	Point a4(390,219);
	Point b4(319,468);
	Point c4(413,20);
	Point p6(250,250);
	Point p7(380, 222);

	std::cout << "a = " << a << "  b = " << b << "  c = " << c << std::endl;
	std::cout << "Is p1" << p1 << " in (a,b,c)? " << bool2msg(bsp(a, b, c, p1)) << std::endl;
	std::cout << "Is p2" << p2 << " in (a,b,c)? " << bool2msg(bsp(a, b, c, p2)) << std::endl;
	std::cout << "Is a" << a << " in (a,b,c)? " << bool2msg(bsp(a, b, c, a)) << std::endl;
	std::cout << std::endl;
	std::cout << "a2 = " << a2 << "  b2 = " << b2 << "  c2 = " << c2 << std::endl;
	std::cout << "Is p3" << p3 << " in (a2,b2,c2)? " << bool2msg(bsp(a2, b2, c2, p3)) << std::endl;
	std::cout << "Is p4" << p4 << " in (a2,b2,c2)? " << bool2msg(bsp(a2, b2, c2, p4)) << std::endl;
	std::cout << std::endl;
	std::cout << "a3 = " << a3 << "  b3 = " << b3 << "  c3 = " << c3 << std::endl;
	std::cout << "Is p5" << p5 << " in (a3,b3,c3)? " << bool2msg(bsp(a3, b3, c3, p5)) << std::endl;
	std::cout << std::endl;
	std::cout << "a4 = " << a4 << "  b4 = " << b4 << "  c4 = " << c4 << std::endl;
	std::cout << "Is p6" << p6 << " in (a4,b4,c4)? " << bool2msg(bsp(a4, b4, c4, p6)) << std::endl;
	std::cout << "Is p7" << p7 << " in (a4,b4,c4)? " << bool2msg(bsp(a4, b4, c4, p7)) << std::endl;
	
	return (0);
}