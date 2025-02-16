#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat b1("John", 50);

    ShrubberyCreationForm form1("home");
    form1.setSigned(true); // Using a public setter if `beSigned()` is still protected
    b1.executeForm(form1);

    RobotomyRequestForm form2("target1");
    form2.setSigned(true);
    b1.executeForm(form2);

    PresidentialPardonForm form3("target2");
    form3.setSigned(true);
    b1.executeForm(form3);

    return 0;
}
