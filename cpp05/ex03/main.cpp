#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	Intern someRandomIntern;

	AForm* robotomyForm = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	if (robotomyForm)
	{
		std::cout << "Successfully created form: " << robotomyForm->getName() << std::endl;
		delete robotomyForm;
	}

	AForm* shrubberyForm = someRandomIntern.makeForm("ShrubberyCreationForm", "home");
	if (shrubberyForm)
	{
		std::cout << "Successfully created form: " << shrubberyForm->getName() << std::endl;
		delete shrubberyForm;
	}

	AForm* pardonForm = someRandomIntern.makeForm("PresidentialPardonForm", "Alice");
	if (pardonForm)
	{
		std::cout << "Successfully created form: " << pardonForm->getName() << std::endl;
		delete pardonForm;
	}

	AForm* invalidForm = someRandomIntern.makeForm("InvalidForm", "Target");
	if (!invalidForm)
		std::cout << "Failed to create form with invalid name." << std::endl;
	return 0;
}
