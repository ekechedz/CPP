#include <iostream>
#include "Array.hpp"

int main() {
	try {
		Array<int> emptyArray;
		std::cout << "Empty array size: " << emptyArray.size() << std::endl;

		Array<int> intArray(5);
		std::cout << "Int array size: " << intArray.size() << std::endl;

		// Assigning values
		for (unsigned int i = 0; i < intArray.size(); i++) {
			intArray[i] = i * 10;
		}

		std::cout << "Int array elements: ";
		for (unsigned int i = 0; i < intArray.size(); i++) {
			std::cout << intArray[i] << " ";
		}
		std::cout << std::endl;

		Array<int> copiedArray(intArray);
		std::cout << "Copied array elements: ";
		for (unsigned int i = 0; i < copiedArray.size(); i++) {
			std::cout << copiedArray[i] << " ";
		}
		std::cout << std::endl;

		// Modifying original array to ensure deep copy
		intArray[0] = 999;
		std::cout << "Modified original array: " << intArray[0] << std::endl;
		std::cout << "Copied array remains unchanged: " << copiedArray[0] << std::endl;

		Array<int> assignedArray;
		assignedArray = intArray;
		std::cout << "Assigned array elements: ";
		for (unsigned int i = 0; i < assignedArray.size(); i++) {
			std::cout << assignedArray[i] << " ";
		}
		std::cout << std::endl;

		// Out-of-bounds access test
		std::cout << "Trying to access an out-of-bounds index..." << std::endl;
		std::cout << intArray[6] << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
