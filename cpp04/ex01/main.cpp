#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;
	delete i;

	std::cout << "\n=== Array of Animals ===" << std::endl;

	Animal *animals[4];
	for (int index = 0; index < 2; ++index)
		animals[index] = new Dog();
	std::cout << std::endl;
	for (int index = 2; index < 4; ++index)
		animals[index] = new Cat();
	std::cout << std::endl;
	for (int index = 0; index < 4; ++index)
		delete animals[index];

	std::cout << "\n=== Deep Copy Test ===" << std::endl;

	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Chase the ball");
	Dog copiedDog = originalDog;
	copiedDog.getBrain()->setIdea(0, "Eat food");

	std::cout << "Original Dog Idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog Idea[0]: " << copiedDog.getBrain()->getIdea(0) << std::endl;

	return 0;
}
