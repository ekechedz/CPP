#include "Span.hpp"
#include <iostream>
#include <limits>

Span::Span(unsigned int n) : _max_size(n) {}

Span::Span(const Span &other) : _max_size(other._max_size), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _max_size = other._max_size;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _max_size)
		throw std::overflow_error("Cannot add more numbers, capacity reached.");
	_numbers.push_back(n);
}


int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("At least two numbers are required to find a span.");

	std::vector<int> sorted_numbers = _numbers;
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	int shortest = std::numeric_limits<int>::max();

	for (size_t i = 1; i < sorted_numbers.size(); ++i)
	{
		int diff = sorted_numbers[i] - sorted_numbers[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("At least two numbers are required to find a span.");

	int min_num = *std::min_element(_numbers.begin(), _numbers.end());
	int max_num = *std::max_element(_numbers.begin(), _numbers.end());

	return max_num - min_num;
}
