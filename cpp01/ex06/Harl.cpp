#include "Harl.hpp"

// Private member functions for each log level
void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do" << std::endl;
    std::cout << "\n";
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    std::cout << "\n";
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
    std::cout << "\n";
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << "\n";
}

// Convert string to integer to use with switch
int Harl::levelToInt(const std::string &level)
{
    if (level == "DEBUG")
        return 0;
    if (level == "INFO")
        return 1;
    if (level == "WARNING")
        return 2;
    if (level == "ERROR")
        return 3;
    return -1; // Default case for unknown levels
}

// Public member function that filters based on level
void Harl::complain(std::string level)
{
    int levelInt = levelToInt(level);

    switch (levelInt)
    {
    case 0: // DEBUG
        debug();
        // fall-through to also print info, warning, and error
    case 1: // INFO
        info();
        // fall-through to also print warning and error
    case 2: // WARNING
        warning();
        // fall-through to also print error
    case 3: // ERROR
        error();
        break;
    default:
        std::cout << "[ I am not sure what to write here ]" << std::endl;
        break;
    }
}
