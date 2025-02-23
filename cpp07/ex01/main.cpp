#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(const T& elem) {
	std::cout << elem << " ";
}

template <typename T>
void increment(T& elem) {
	++elem;
}

int main() {
	// Testing with int array
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original int array: ";
	iter(intArray, intSize, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intSize, increment<int>);
	std::cout << "After increment: ";
	iter(intArray, intSize, printElement<int>);
	std::cout << std::endl;

	// Testing with double array
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Original double array: ";
	iter(doubleArray, doubleSize, printElement<double>);
	std::cout << std::endl;

	iter(doubleArray, doubleSize, increment<double>);
	std::cout << "After increment: ";
	iter(doubleArray, doubleSize, printElement<double>);
	std::cout << std::endl;

	// Testing with a character array
	char charArray[] = {'a', 'b', 'c', 'd'};
	size_t charSize = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Original char array: ";
	iter(charArray, charSize, printElement<char>);
	std::cout << std::endl;

	iter(charArray, charSize, increment<char>);
	std::cout << "After increment: ";
	iter(charArray, charSize, printElement<char>);
	std::cout << std::endl;

	return 0;
}
