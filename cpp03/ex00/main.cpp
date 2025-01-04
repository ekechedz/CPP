#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");

    clap.attack("Target1");
    clap.takeDamage(3);
    clap.beRepaired(5);

    ClapTrap copyClap = clap;
    copyClap.attack("Target2");

    ClapTrap assignedClap("Assigned");
    assignedClap = clap;
    assignedClap.takeDamage(15);

    return 0;
}
