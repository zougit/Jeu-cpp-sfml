#ifndef ARMOR_HPP
#define ARMOR_HPP

#include <iostream>

class Armor
{
    public:
        Armor();
        Armor(std::string name, int resistance);
        void changeArmor(std::string name, int resistance);
        void displayArmor();
        std::string getName() const;
        int getResistance() const;
        bool isEquipped() const;

    private:
        std::string _name;
        int _resistance;
        bool _isEquipped;
};

#endif