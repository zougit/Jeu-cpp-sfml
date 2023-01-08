#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    public:
        Weapon();
        Weapon(std::string name, int damage);
        void changeWeapon(std::string name, int damage);
        void displayWeapon();
        std::string getName() const;
        int getDamage() const;
        bool isEquipped() const;

    private:
        std::string _name;
        int _damage;
        bool _isEquipped;
};

#endif