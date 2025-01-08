#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Default Constructor Test ===" << std::endl;
    ClapTrap clapDefault;
    ScavTrap scavDefault;

    std::cout << "\n=== Parameterized Constructor Test ===" << std::endl;
    ClapTrap clapParam("Clappy");
    ScavTrap scavParam("Scavvy");

    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    ClapTrap clapCopy(clapParam);
    ScavTrap scavCopy(scavParam);

    std::cout << "\n=== Copy Assignment Test ===" << std::endl;
    ClapTrap clapAssigned;
    ScavTrap scavAssigned;
    clapAssigned = clapParam;
    scavAssigned = scavParam;

    std::cout << "\n=== Testing Special Functionalities ===" << std::endl;
    scavParam.guardGate();

    std::cout << "\n=== Destruction Test ===" << std::endl;
    return 0;
}
