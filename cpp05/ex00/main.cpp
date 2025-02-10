#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Elmira", 1);
        std::cout << b1 << std::endl;
        
        b1.decrementGrade();
        std::cout << b1 << std::endl;

        Bureaucrat b2("Nil", 3);
        std::cout << b2 << std::endl;
        
        b2.incrementGrade();
        std::cout << b2 << std::endl;

        Bureaucrat b3("Charlie", 0);
    } 
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
