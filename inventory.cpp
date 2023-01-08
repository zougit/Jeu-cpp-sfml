#include "headers/inventory.hpp"

using namespace std;

Inventory::Inventory()
{
}

vector<Weapon> Inventory::getWeapon() const
{
    return _weapons;
}

vector<Armor> Inventory::getArmor() const
{
    return _armors;
}

vector<Heal> Inventory::getHeal() const
{
    return _heals;
}

vector<vector<Item>> Inventory::getItem() const
{
    return _items;
}

void Inventory::addWeapon (Weapon weapon) {
    _weapons.push_back(weapon);
}

void Inventory::addArmor (Armor armor) {
    _armors.push_back(armor);
}

void Inventory::addHeal (Heal heal) {
    _heals.push_back(heal);
}

void Inventory::addItem (Item item, string type) {
    if (type == "plante")
    cout << _items.size() << endl ;
        _items[0].push_back(item);
    cout << _items.size() << endl ;
        cout << _items[0][_items.size()-1].getName() << endl;
    if (type == "minerai")
        _items[1].push_back(item);
}
