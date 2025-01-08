#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    // Orthodox Canonical Form
    WrongCat();                                 // Default Constructor
    WrongCat(const WrongCat &other);            // Copy Constructor
    WrongCat &operator=(const WrongCat &other); // Copy Assignment Operator
    ~WrongCat();                                // Destructor

    // Member function
    void makeSound() const;
};

#endif
