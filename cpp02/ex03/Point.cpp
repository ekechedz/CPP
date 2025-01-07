/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:06:13 by ekechedz          #+#    #+#             */
/*   Updated: 2025/01/07 16:06:15 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::~Point() {}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}
