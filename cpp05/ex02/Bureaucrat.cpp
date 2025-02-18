#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1) throw GradeTooHighException(grade);
	if (grade > 150) throw GradeTooLowException(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() { }

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1) throw GradeTooHighException(_grade - 1);
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150) throw GradeTooLowException(_grade + 1);
	++_grade;
}

void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int grade) : grade(grade) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	std::ostringstream oss;
	int difference = std::abs(grade - 1);
	oss << "Grade is too high: " << grade << ". It is " << difference << " too high.";
	message = oss.str();
	return message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int grade) : grade(grade) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	std::ostringstream oss;
	int difference = std::abs(grade - 150);
	oss << "Grade is too low: " << grade << ". It is " << difference << " too low.";
	message = oss.str();
	return message.c_str();
}
