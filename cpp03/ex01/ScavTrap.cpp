#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed!" << std::endl;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << name << " copied!" << std::endl;
}

// Assignment Operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap " << name << " assigned!" << std::endl;
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destructed!" << std::endl;
}

// Overriding attack
void ScavTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        --energyPoints;
        std::cout << "ScavTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << name << " has no energy or hit points to attack!" << std::endl;
    }
}

// New functionality: guardGate
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}
