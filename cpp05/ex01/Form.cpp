#include "Form.hpp"
#include "Bureaucrat.hpp"

// Exception messages
const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

// Constructor with validation
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
    {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150)
    {
        throw GradeTooLowException();
    }
}

// Destructor
Form::~Form() {}

// Copy Constructor
Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

// Copy Assignment Operator
Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned; // Name and grades are const, so can't be reassigned
    }
    return *this;
}

// Getters
std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

// beSigned function
void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
    }
    isSigned = true;
}

// Print function
std::ostream &Form::print(std::ostream &out) const
{
    out << "Form: " << name << ", Signed: " << (isSigned ? "Yes" : "No")
        << ", Required Grade to Sign: " << gradeToSign
        << ", Required Grade to Execute: " << gradeToExecute;
    return out;
}

// Overloaded << operator
std::ostream &operator<<(std::ostream &out, const Form &f)
{
    return f.print(out);
}
