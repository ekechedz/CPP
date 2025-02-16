#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat; // Forward declaration

class AForm {
public:
    virtual ~AForm();
    virtual void execute(Bureaucrat const & executor) const = 0;

    bool isSigned() const;
    std::string getTarget() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void setSigned(bool value) { _signed = value; }


protected:
    AForm(std::string const & target, int signGrade, int execGrade);



private:
    std::string const _target;
    int const _signGrade;
    int const _execGrade;
    bool _signed;
};

#endif
