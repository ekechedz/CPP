#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // ClapTrap test
    ClapTrap clap("Clappy");
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(10);

    std::cout << "------" << std::endl;

    // ScavTrap test
    ScavTrap scav("Scavvy");
    scav.attack("Target2");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();

    std::cout << "------" << std::endl;

    // ScavTrap copy and assignment
    ScavTrap scavCopy = scav;
    ScavTrap scavAssigned("AnotherScav");
    scavAssigned = scav;

    return 0;
}
