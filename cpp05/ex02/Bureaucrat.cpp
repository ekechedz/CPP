#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade) {}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getTarget() << std::endl;
    } catch (const std::exception &e) {
        std::cout << _name << " failed to execute " << form.getTarget() << " because: " << e.what() << std::endl;
    }
}
