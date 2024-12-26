#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie *heapZombie;
    heapZombie = newZombie("Zombie1");
    heapZombie->announce();
    delete heapZombie;
    randomChump("Zombie2");

    return 0;
}
