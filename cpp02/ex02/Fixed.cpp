/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:01:45 by ekechedz          #+#    #+#             */
/*   Updated: 2025/01/07 16:01:47 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int intValue)
{
	this->value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	this->value = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->value = other.value;
	}
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->value >> fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->value + other.value);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->value - other.value);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->value * other.value) >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	if (other.value != 0)
		result.setRawBits((this->value << fractionalBits) / other.value);
	return result;
}

Fixed &Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
