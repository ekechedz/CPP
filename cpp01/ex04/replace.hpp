#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <fstream>
#include <iostream>

class Replace
{
public:
    static bool process(const std::string &filename, const std::string &s1, const std::string &s2);
};

#endif
