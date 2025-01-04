#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    // Constructors
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    // Member functions
    void attack(const std::string &target); // Overrides ClapTrap's attack
    void guardGate();                       // New functionality for ScavTrap
};

#endif // SCAVTRAP_HPP
