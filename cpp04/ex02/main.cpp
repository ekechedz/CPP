#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Testing abstract functionality
	//const AAnimal *animal = new AAnimal(); // ERROR: Cannot instantiate abstract class

	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	return 0;
}
