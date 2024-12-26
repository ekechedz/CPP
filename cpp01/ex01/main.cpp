#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
    int hordeSize = 5;
    int i = 0;
    std::string zombieName = "HordeZombie";

    Zombie *horde = zombieHorde(hordeSize, zombieName);
    if (horde)
    {
        while(i < hordeSize)
        {
            horde[i].announce();
            i++;
        }
        delete[] horde;
    }
    else
        std::cout << "Failed to create a zombie horde." << std::endl;
    return 0;
}
