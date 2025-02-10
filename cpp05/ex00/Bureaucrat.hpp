#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // using this to can access the private 
    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    // Overloaded output operator (moved inside class)
    std::ostream& print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
