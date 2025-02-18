#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter(void){}
		ScalarConverter(const ScalarConverter &src) {(void)src;}
		ScalarConverter &operator=(const ScalarConverter &src)
		{
			(void)src;
			return *this;
		}
		~ScalarConverter(void){}

	public:
		static void converter(const std::string &literal);
};

#endif
