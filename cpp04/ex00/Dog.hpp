#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    // Orthodox Canonical Form
    Dog();                            // Default Constructor
    Dog(const Dog &other);            // Copy Constructor
    Dog &operator=(const Dog &other); // Copy Assignment Operator
    ~Dog();                           // Destructor

    // Overridden makeSound function
    void makeSound() const; // No override keyword in C++98
};

#endif
