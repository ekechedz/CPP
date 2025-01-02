#include "Fixed.hpp"

// Initialize the static member
const int Fixed::fractionalBits = 8;

// Default constructor
Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Integer constructor
Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = intValue << fractionalBits; // Convert integer to fixed-point
}

// Floating-point constructor
Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(floatValue * (1 << fractionalBits)); // Convert float to fixed-point
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // Use the copy assignment operator
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->value = other.value; // Copy the raw value
    }
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Getter for raw value
int Fixed::getRawBits(void) const
{
    return this->value;
}

// Setter for raw value
void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

// Converts to floating-point
float Fixed::toFloat(void) const
{
    return static_cast<float>(this->value) / (1 << fractionalBits);
}

// Converts to integer
int Fixed::toInt(void) const
{
    return this->value >> fractionalBits;
}

// Overload for the << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
