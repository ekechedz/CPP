/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:04:23 by ekechedz          #+#    #+#             */
/*   Updated: 2025/01/07 16:12:39 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

	Point &operator=(const Point &other);

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};

#endif
