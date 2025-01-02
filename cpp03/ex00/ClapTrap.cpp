#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : Name(name), hitPoints(10), energyPoints(10), attackDamage(0){
        std::cout << "ClapTrap " << Name << " has been created!" << std::endl;
    }


ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        Name = other.Name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {    if(amount >= hitPoints)
           hitPoints = 0;
        else
            hitPoints -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << Name << " is already dead!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(hitPoints > 0 && energyPoints > 0)
    {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ClapTrap " << Name << " is repaired by " << amount << " points!" << std::endl;
    }
}
void ClapTrap::attack(const std::string& target)
{
    if(hitPoints > 0 && energyPoints > 0)
    {  
        energyPoints--;
        std::cout << "ClapTrap " << Name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
}
