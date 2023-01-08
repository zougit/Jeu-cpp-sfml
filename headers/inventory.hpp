#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "weapon.hpp"
#include "armor.hpp"
#include "heal.hpp"
#include "item.hpp"
#include <vector>
#include <iostream>

class Inventory
{
    public:
        Inventory();
        std::vector<Weapon> getWeapon() const;
        std::vector<Armor> getArmor() const;
        std::vector<Heal> getHeal() const;
        std::vector<std::vector<Item>> getItem() const;
        void addWeapon(Weapon weapon);
        void addArmor(Armor armor);
        void addHeal(Heal heal);
        void addItem(Item item,std::string type);
//FIXME - initialiser les vector
    private:
        std::vector<Weapon>  _weapons;
        std::vector<Armor> _armors;
        std::vector<Heal> _heals;
        std::vector<std::vector<Item>> _items;
};

#endif