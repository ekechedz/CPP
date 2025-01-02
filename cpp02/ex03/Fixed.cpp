#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int intValue)
{
    _value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    _value = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        _value = other.getRawBits();
    }
    return *this;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_value + other.getRawBits());
    return result;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_value == other.getRawBits();
}

Fixed Fixed::abs() const
{
    return Fixed(this->_value < 0 ? -this->_value : this->_value);
}

int Fixed::getRawBits() const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(_value) / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return _value >> fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
