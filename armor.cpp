#include "headers/armor.hpp"
using namespace std;

Armor::Armor(): _name("chemise sale"), _resistance(1), _isEquipped(true)
{}

Armor::Armor(string name, int resistance):
    _name(name), _resistance(resistance), _isEquipped(false)
{}

void Armor::changeArmor(string name, int resistance)
{
    _resistance = resistance;
    _name = name;
}

void Armor::displayArmor() {
    string res = (_isEquipped == true) ? "oui" : "non";
    cout << "name: " << _name << endl
         << "resistance: " << _resistance << endl
         << "equipped: " << res << endl;
}

string Armor::getName() const {
    return _name;
}

int Armor::getResistance() const {
    return _resistance;
}

bool Armor::isEquipped() const {
    return _isEquipped;
}