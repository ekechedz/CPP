#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <stdexcept>

class ValueNotFoundException : std::exception {
public:
	virtual const char* what() const throw() {
		return "Value not found";
	}
};

template <typename T>
typename T::value_type easyfind(const T &container, int needle) {
	typename T::const_iterator result = find(container.begin(), container.end(), needle);
	if (result == container.end())
		throw ValueNotFoundException();
	return *result;
};

#endif
