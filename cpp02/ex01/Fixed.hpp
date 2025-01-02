#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;                       // Fixed-point value
    static const int fractionalBits; // Number of fractional bits (always 8)

public:
    Fixed();                              // Default constructor
    Fixed(const int intValue);            // Integer constructor
    Fixed(const float floatValue);        // Floating-point constructor
    Fixed(const Fixed &other);            // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment operator
    ~Fixed();                             // Destructor

    int getRawBits(void) const;     // Getter for raw value
    void setRawBits(int const raw); // Setter for raw value
    float toFloat(void) const;      // Converts to floating-point
    int toInt(void) const;          // Converts to integer

    // Overload for the << operator
    friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif
