#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>

bool isChar(const std::string &literal)
{
	return literal.length() == 1 && std::isprint(literal[0]) \
	&& !std::isdigit(literal[0]);
}

bool isInt(const std::string &literal)
{
	char *end = NULL;
	long num = std::strtol(literal.c_str(), &end, 10);
	return end != literal.c_str() && *end == '\0' \
	&& num >= std::numeric_limits<int>::min() \
	&& num <= std::numeric_limits<int>::max();
}

bool isFloat(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	char *end = NULL;
	std::strtof(literal.c_str(), &end);
	return end != literal.c_str() && *end == 'f' && *(end + 1) == '\0';
}


bool isDouble(const std::string &literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	char *end = NULL;
	std::strtod(literal.c_str(), &end);
	return end != literal.c_str() && *end == '\0';
}

void ScalarConverter::converter(const std::string &literal)
{
	if(isChar(literal))
	{
		std::cout << "char: '" << literal[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
	}
	else if(isInt(literal))
	{
		int num = std::atoi(literal.c_str());
		std::cout << "char: " << (num >=32 && num <= 126 \
			? std::string(1, static_cast<char>(num)) : "Non displayable") << std::endl;
		std::cout << "int: " << num << std::endl;
		std::cout << "float " << static_cast<float>(num) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) <<".0" << std::endl;
	}
	else if (isFloat(literal))
	{
		if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << (literal == "nanf" ? "nan" : literal) << std::endl;
		}
		else
		{
			float num = std::strtof(literal.c_str(), NULL);
			std::cout << "char: " << (num >= 32 && num <= 126 ? std::string(1, static_cast<char>(num)) : "Non displayable") << std::endl;
			std::cout << "int: " << static_cast<int>(num) << std::endl;
			std::cout << "float: " << num << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(num) << std::endl;
		}
	}
	else if (isDouble(literal))
	{
		if (literal == "-inf" || literal == "+inf" || literal == "nan")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << (literal == "nan" ? "nanf" : literal + "f") << std::endl;
			std::cout << "double: " << literal << std::endl;
		}
		else
		{
			double num = std::strtod(literal.c_str(), NULL);
			std::cout << "char: " << (num >= 32 && num <= 126 ? std::string(1, static_cast<char>(num)) : "Non displayable") << std::endl;
			std::cout << "int: " << static_cast<int>(num) << std::endl;
			std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
			std::cout << "double: " << num << std::endl;
		}
	}
	else
		std::cout << "This is not char, int, float or double" << std::endl;

}
