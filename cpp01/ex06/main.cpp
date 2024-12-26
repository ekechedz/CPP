#include "Harl.hpp"

int main(int argc, char **argv)
{
    // Check if there is exactly one argument (besides the program name)
    if (argc != 2)
    {
        std::cout << "Usage: ./harlFilter <log_level>" << std::endl;
        return 1; // Return an error code if arguments are incorrect
    }

    // Create an instance of the Harl class
    Harl harl;

    // Call the complain function with the provided log level
    harl.complain(argv[1]);

    return 0; // Return success
}
