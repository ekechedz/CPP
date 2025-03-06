#include "RPN.hpp"


RPN::RPN() {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &src) {
	if (this != &src)
		return *this;
	return *this;
}

void RPN::evaluate(const std::string& expr) {
	std::stack<int> stack;
	std::stringstream ss(expr);
	std::string token;

	while (ss >> token)
	{
		if (isNumber(token))
			stack.push(atoi(token.c_str()));
		else if (isOperator(token))
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			performOperation(token[0]);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}

	if (stack.size() != 1)
		std::cerr << "Error" << std::endl;
	else
		std::cout << stack.top() << std::endl;
}

void RPN::performOperation(char op) {
	std::stack<int> stack;
	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();

	int result;
	switch (op) {
		case '+': result = a + b; break;
		case '-': result = a - b; break;
		case '*': result = a * b; break;
		case '/':
			if (b == 0) {
				std::cerr << "Error" << std::endl;
				return;
			}
			result = a / b;
			break;
		default:
			std::cerr << "Error" << std::endl;
			return;
	}
	stack.push(result);
}

bool RPN::isOperator(const std::string& token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token) {
	return !token.empty() && std::isdigit(token[0]);
}
