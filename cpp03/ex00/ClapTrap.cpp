#include "ClapTrap.hpp"


ClapTrap::ClapTrap(const std::string &name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << name << " copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned!" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        --energyPoints;
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints = (amount >= hitPoints) ? 0 : hitPoints - amount;
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! Remaining HP: " << hitPoints << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        --energyPoints;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " repairs itself for "
                  << amount << " hit points! Total HP: " << hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points to repair!" << std::endl;
    }
}
