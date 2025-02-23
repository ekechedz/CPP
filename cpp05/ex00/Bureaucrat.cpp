#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high! Maximum allowed is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low! Minimum allowed is 150.";
}


Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade - 1 < 1) {
		throw GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > 150) {
		throw GradeTooLowException();
	}
	grade++;
}

std::ostream& Bureaucrat::print(std::ostream& out) const {
	out << name << ", bureaucrat grade " << grade;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	return b.print(out);
}
