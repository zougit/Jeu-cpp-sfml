#include "headers/weapon.hpp"
using namespace std;

Weapon::Weapon(): _name("mains nus"), _damage(1), _isEquipped(true)
{}

Weapon::Weapon(string name, int damage):
    _name(name), _damage(damage), _isEquipped(false)
{}

void Weapon::changeWeapon(string name, int damage)
{
    _damage = damage;
    _name = name;
}

void Weapon::displayWeapon() {
    string res = (_isEquipped == true) ? "oui" : "non";
    cout << "name: " << _name << endl
         << "damage: " << _damage << endl
         << "equipped: " << res << endl;
}

string Weapon::getName() const {
    return _name;
}

int Weapon::getDamage() const {
    return _damage;
}

bool Weapon::isEquipped() const {
    return _isEquipped;
}