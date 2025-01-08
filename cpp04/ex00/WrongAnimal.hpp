#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;

public:
    // Orthodox Canonical Form
    WrongAnimal();                                    // Default Constructor
    WrongAnimal(const WrongAnimal &other);            // Copy Constructor
    WrongAnimal &operator=(const WrongAnimal &other); // Copy Assignment Operator
    ~WrongAnimal();                                   // Destructor

    // Getter for type
    std::string getType() const;

    // Member function (not virtual in C++98)
    void makeSound() const;
};

#endif
