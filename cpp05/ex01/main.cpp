#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 100);

        Form f1("Top Secret Form", 50, 30);
        Form f2("Basic Form", 120, 100);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        b1.signForm(f1); // Should work
        b2.signForm(f1); // Should fail

        b1.signForm(f2); // Should work
        b2.signForm(f2); // Should work

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
