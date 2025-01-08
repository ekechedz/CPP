#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    // Orthodox Canonical Form
    Cat();                            // Default Constructor
    Cat(const Cat &other);            // Copy Constructor
    Cat &operator=(const Cat &other); // Copy Assignment Operator
    ~Cat();                           // Destructor

    // Overridden makeSound function
    void makeSound() const; // No override keyword in C++98
};

#endif
