#include <iostream>
#include <cctype>

char toUpper(char c)
{
    return std::toupper(c);
}

int main(int argc, char **argv)
{
    if(argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }
    int i = 1;
    while (i < argc)
    {
        int j = 0;
        while (argv[i][j])
        { 
            std::cout << toUpper(argv[i][j]);
            j++;
        }
        if (i < argc - 1)
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;
    return 0;
}
