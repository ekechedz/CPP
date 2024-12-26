#include "Replace.hpp"

bool Replace::process(const std::string &filename, const std::string &s1, const std::string &s2)
{
    if(s1.empty() || s2.empty())
    {
        std::cerr << "Error: s1 or s2 is empty" << std::endl;
        return false;
    }
    std::ifstream infile(filename);
    if(!infile.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return false;
    }
    std::string content((std::istreambuf_iterator<char>(infile)), 
                        (std::istreambuf_iterator<char>())); // read file into a string
    infile.close();
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    std::ofstream outfile(filename + ".replace");
    if(!outfile.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return false;
    }
    outfile << content;
    outfile.close();
    return true;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage" << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    if(!Replace::process(av[1], av[2], av[3]))
        return 1;
    std::cout << "File processed successfully. Output written to" << av[1] << ".replace" << std::endl;
    return 0;
}