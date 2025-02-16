#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"

class Bureaucrat {
public:
    Bureaucrat(std::string name, int grade);

    std::string getName() const;
    int getGrade() const;

    void executeForm(AForm const & form) const;

private:
    std::string const _name;
    int _grade;
};

#endif
