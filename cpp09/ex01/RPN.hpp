#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>

class RPN {
public:
	RPN();
	RPN(const RPN &src);
	~RPN();
	RPN &operator=(const RPN &src);
	void evaluate(const std::string& expr);

private:
	void performOperation(char op);
	bool isOperator(const std::string& token);
	bool isNumber(const std::string& token);
};

#endif
