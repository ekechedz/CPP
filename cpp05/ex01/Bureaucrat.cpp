#include "Bureaucrat.hpp"
#include "Form.hpp"

// Exception messages
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! Maximum allowed is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! Minimum allowed is 150.";
}

// Constructor with validation
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade = other.grade;  // Name is constant and cannot be reassigned
    }
    return *this;
}

// Getters
std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// Increment & Decrement functions with validation
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

// Print function (used in << operator overload)
std::ostream& Bureaucrat::print(std::ostream& out) const {
    out << name << ", bureaucrat grade " << grade;
    return out;
}

void Bureaucrat::signForm(Form& f) {
    try {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << name << " couldn't sign " << f.getName()
                  << " because " << e.what() << std::endl;
    }
}


// Overloaded << operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    return b.print(out);
}
