#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);            // Copy Constructor
    ClapTrap &operator=(const ClapTrap &other); // Assignment Operator
    ~ClapTrap();                                // Destructor

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
