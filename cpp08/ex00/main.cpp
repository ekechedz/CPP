#include <iostream>
#include <list>
#include <string>
#include "easyfind.hpp"

int main(void) {
	int i;

	std::list<int> empty_list;
	int arr[] = {1, 2, 4};
	std::list<int> int_list(arr, arr + 3);

	try {
		i = easyfind(int_list, 2);
		std::cout << "Found value: " << i << std::endl;
	} catch (const ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		i = easyfind(int_list, 1);
		std::cout << "Found value: " << i << std::endl;
	} catch (const ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		i = easyfind(int_list, 4);
		std::cout << "Found value: " << i << std::endl;
	} catch (const ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		i = easyfind(empty_list, 0);
		std::cout << "Found value: " << i << std::endl;
	} catch (const ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}
}
