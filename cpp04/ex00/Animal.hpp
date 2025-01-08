#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;

public:
    // Orthodox Canonical Form
    Animal();                               // Default Constructor
    Animal(const Animal &other);            // Copy Constructor
    Animal &operator=(const Animal &other); // Copy Assignment Operator
    virtual ~Animal();                      // Virtual Destructor

    // Getter for type
    std::string getType() const;

    // Virtual member function
    virtual void makeSound() const; // Virtual method to be overridden
};

#endif
