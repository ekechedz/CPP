#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

RPN::RPN() { }
RPN::~RPN() { }

const char* RPN::InvalidExpressionException::what() const throw() {
	return "Invalid RPN expression";
}

const char* RPN::DivisionByZeroException::what() const throw() {
	return "Division by zero";
}

int RPN::evaluateExpression(const std::string &expression) throw(InvalidExpressionException, DivisionByZeroException) {
	std::stack<int> valueStack;
	std::istringstream inputStream(expression);
	std::string currentToken;

	while (inputStream >> currentToken) {
		if (currentToken.size() == 1 && _isOperator(currentToken[0])) {
			if (valueStack.size() < 2)
				throw InvalidExpressionException();
			int rightOperand = _pop(valueStack);
			int leftOperand = _pop(valueStack);
			valueStack.push(_calculateOperation(leftOperand, rightOperand, currentToken[0]));
		} else {
			for (size_t i = 0; i < currentToken.length(); ++i) {
				if (!std::isdigit(currentToken[i]))
					throw InvalidExpressionException();
			}
			valueStack.push(std::atoi(currentToken.c_str()));
		}
	}

	if (valueStack.size() != 1)
		throw InvalidExpressionException();

	return valueStack.top();
}

int RPN::_calculateOperation(int leftOperand, int rightOperand, char operation) throw(DivisionByZeroException) {
	switch (operation) {
		case '+': return leftOperand + rightOperand;
		case '-': return leftOperand - rightOperand;
		case '*': return leftOperand * rightOperand;
		case '/':
			if (rightOperand == 0) throw DivisionByZeroException();
			return leftOperand / rightOperand;
		default:
			throw InvalidExpressionException();
	}
}

bool RPN::_isValidCharacter(char character) {
	return std::isdigit(character) || _isOperator(character) || std::isspace(character);
}

bool RPN::_isOperator(char character) {
	return character == '+' || character == '-' || character == '*' || character == '/';
}
