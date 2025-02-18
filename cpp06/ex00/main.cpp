#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: "<< av[0] << "literal" << std::endl;
		return 1;
	}
	std::string literal = av[1];
	ScalarConverter::converter(literal);
	return 0;
}
