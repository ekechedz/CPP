#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
	unsigned int _max_size;
	std::vector<int> _numbers;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &src);
	Span &operator=(const Span &src);
	~Span();
	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;
};

#endif
