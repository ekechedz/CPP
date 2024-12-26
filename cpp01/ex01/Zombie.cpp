#include "Zombie.hpp"

Zombie::Zombie() : name("") {} // Default constructor

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
    std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
