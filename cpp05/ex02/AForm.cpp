#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const & target, int signGrade, int execGrade)
    : _target(target), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {}

AForm::~AForm() {}

bool AForm::isSigned() const {
    return _signed;
}

std::string AForm::getTarget() const {
    return _target;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

