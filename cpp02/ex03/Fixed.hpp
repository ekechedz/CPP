/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:06:44 by ekechedz          #+#    #+#             */
/*   Updated: 2025/01/07 16:07:23 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed &operator=(const Fixed &other);
	Fixed operator+(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	Fixed abs() const;

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
