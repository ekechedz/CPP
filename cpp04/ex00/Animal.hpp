#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;

public:

    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();                      // Virtual Destructor

    // Getter for type
    std::string getType() const;

    // Virtual member function
    virtual void makeSound() const; // Virtual method to be overridden
};

#endif
