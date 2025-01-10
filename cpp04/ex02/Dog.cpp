#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		*brain = *other.brain; // Deep copy
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound: Woof woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return brain;
}
