#include "PresidentialPardonForm.hpp"
#include <stdexcept>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
    : AForm(target, 25, 5) {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > getExecGrade()) throw std::runtime_error("Grade too low to execute");

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
