#ifndef PNJ_HPP
#define PNJ_HPP

#include <iostream>

class Pnj
{
public:
    Pnj();
    Pnj(std::string name, std::string job);
    ~Pnj();
    void displayPnj();

private:
    std::string _name;
    std::string _job;
};

#endif