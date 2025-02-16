#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
    : AForm(target, 72, 45) {
    std::srand(std::time(0));
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > getExecGrade()) throw std::runtime_error("Grade too low to execute");

    std::cout << "Drilling noises...\n";
    if (std::rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << getTarget() << std::endl;
}
