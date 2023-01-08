#ifndef HEAL_HPP
#define HEAL_HPP

#include <iostream>

class Heal
{
    public:
        Heal();
        Heal(std::string name, int healing);
        void displayHeal();
        std::string getName() const;
        int getHealing() const;

    private:
        std::string _name;
        int _healing;
};

#endif