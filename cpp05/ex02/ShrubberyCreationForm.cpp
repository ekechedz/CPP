#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw std::runtime_error("Form not signed.");
    }
    if (executor.getGrade() > getExecGrade()) {
        throw std::runtime_error("Grade too low to execute.");
    }

    // Use std::string concatenation to create the file name
    std::string fileName = getTarget() + "_shrubbery";
    std::ofstream outFile(fileName);

    if (outFile.is_open()) {
        outFile << "ASCII trees...\n";
        outFile.close();
    } else {
        throw std::runtime_error("Failed to open file.");
    }
}
