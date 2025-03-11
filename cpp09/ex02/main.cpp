#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <sstream>
#include <string>

int main(int argc, char** argv) {

	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int> input_values;
	for (int i = 1; i < argc; ++i)
	{
		int value;
		std::istringstream iss(argv[i]);
		if (!(iss >> value) || value <= 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		input_values.push_back(value);
	}

	std::deque<int> input_deque(input_values.begin(), input_values.end());
	std::cout << "Before: ";
	for (std::size_t i = 0; i < input_values.size(); ++i)
		std::cout << input_values[i] << " ";
	std::cout << std::endl;

	clock_t start = clock();
	MergeInsertSorter sorter;
	sorter.merge_insertion_sort(input_values);
	clock_t end = clock();
	double vec_duration = (double)(end - start) / CLOCKS_PER_SEC;


	std::cout << "After: ";
	for (std::size_t i = 0; i < input_values.size(); ++i)
		std::cout << input_values[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << input_values.size() << " elements with std::vector : "
			  << vec_duration * 1e6 << " us" << std::endl;

	start = clock();
	sorter.merge_insertion_sort(input_deque);
	end = clock();
	double deque_duration = (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << input_deque.size() << " elements with std::deque : "
			  << deque_duration * 1e6 << " us" << std::endl;

	return 0;
}
