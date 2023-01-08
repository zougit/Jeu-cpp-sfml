#include "headers/heal.hpp"
using namespace std;

Heal::Heal(): _name("potion 1"), _healing(20)
{}

Heal::Heal(string name, int healing):
    _name(name), _healing(healing)
{}


void Heal::displayHeal() {
    cout << "name: " << _name << endl
         << "healing: " << _healing << endl;
}

string Heal::getName() const {
    return _name;
}

int Heal::getHealing() const {
    return _healing;
}
