/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:47:38 by mamuller          #+#    #+#             */
/*   Updated: 2022/04/20 20:47:38 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point a, Point b, Point c, const Point point)
{
	Fixed dXpc = point.getX() - c.getX();
	Fixed dYpc = point.getY() - c.getY();
	Fixed dXcb = c.getX() - b.getX();
	Fixed dYbc = b.getY() - c.getY();
	Fixed dXac = a.getX() - c.getX();
	Fixed D = dYbc * dXac + dXcb*(a.getY()-c.getY());
	Fixed s = dYbc*dXpc + dXcb*dYpc;
	Fixed t = (c.getY()-a.getY())*dXpc + dXac * dYpc;
	if (D<0)
		return (s<0 && t<0 && (s+t>D));
	return (s>0 && t>0 && (s+t<D));
};