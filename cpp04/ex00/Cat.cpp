#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called!" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other); // Call base class assignment
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat sound: Meow!" << std::endl;
}
