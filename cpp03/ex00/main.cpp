#include "ClapTrap.hpp"

int main()
{
    // Create a ClapTrap object
    ClapTrap claptrap1("Clappy");

    // Test attack
    claptrap1.attack("Target1");

    // Test taking damage
    claptrap1.takeDamage(5);
    claptrap1.takeDamage(10); // This should set hitPoints to 0

    // Test repairing
    claptrap1.beRepaired(5); // This should repair the ClapTrap, if possible

    // Test another ClapTrap object using the copy constructor
    ClapTrap claptrap2 = claptrap1;

    // Test the assignment operator
    ClapTrap claptrap3("Copy");
    claptrap3 = claptrap1;

    // Test attack after copying
    claptrap2.attack("Target2");

    return 0;
}
