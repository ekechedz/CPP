#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	std::srand(std::time(0));
	int randVal = std::rand() % 3;

	if(randVal == 0)
		return new A();
	else if (randVal == 1)
		return new B();
	else
		return new C();
}
