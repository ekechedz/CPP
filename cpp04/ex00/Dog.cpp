#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called!" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other); // Call base class assignment
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound: Woof woof!" << std::endl;
}
