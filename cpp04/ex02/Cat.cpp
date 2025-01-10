#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		*brain = *other.brain; // Deep copy
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound: Meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brain;
}
