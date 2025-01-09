#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called!" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " has been constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap copy assignment operator called!" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}
