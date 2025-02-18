#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecutionRequirements(executor);
	std::cout << "* Drilling noises *" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2) {
		std::cout << target << " has been robotomized successfully." << std::endl;
	}
	else
	{
		std::cout << "The robotomy failed on " << target << "." << std::endl;
	}
}
