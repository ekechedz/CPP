
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{

	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm shrubbery("home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Alice");

		std::cout << "Testing ShrubberyCreationForm:" << std::endl;
		bob.signForm(shrubbery);
		bob.executeForm(shrubbery);

		std::cout << "\nTesting RobotomyRequestForm:" << std::endl;
		bob.signForm(robotomy);
		bob.executeForm(robotomy);

		std::cout << "\nTesting PresidentialPardonForm:" << std::endl;
		bob.signForm(pardon);
		bob.executeForm(pardon);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 1 failed: " << e.what() << std::endl;
	}

	// Test 2: Invalid grade bureaucrat
	try
	{
		Bureaucrat alice("Alice", 160);
		ShrubberyCreationForm shrubbery("home");
		alice.signForm(shrubbery);
		alice.executeForm(shrubbery);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 2 failed: " << e.what() << std::endl;
	}

	return 0;
}
