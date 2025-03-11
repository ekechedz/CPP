#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iterator>
#include <string>

class RPN {
public:
	class InvalidExpressionException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class DivisionByZeroException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	static int evaluateExpression(const std::string &expression) throw(InvalidExpressionException, DivisionByZeroException);

private:
	RPN();
	~RPN();

	static int _performCalculation(std::stack<int> &valueStack) throw(InvalidExpressionException, DivisionByZeroException);
	static int _calculateOperation(int leftOperand, int rightOperand, char operation) throw(DivisionByZeroException);
	static bool _isValidCharacter(char character);
	static bool _isOperator(char character);

	template <typename T>
	static T _pop(std::stack<T> &valueStack) {
		T result = valueStack.top();
		valueStack.pop();
		return result;
	}
};

#endif
