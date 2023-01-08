#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "weapon.hpp"
#include "armor.hpp"
#include "monster.hpp"
#include "initList.hpp"
#include "inventory.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();
    Player(std::string name);
    Player(std::string name, int currentHp, int hpMax, int currentExp, int expMax, int lvl, int x, int y, Weapon weapon,Armor armor,Inventory inventory);
    std::string getName() const;
    int getCurrentHp() const;
    int getHpMax() const;
    int getCurrentExp() const;
    int getExpMax() const;
    int getLvl() const;
    int getX() const;
    int getY() const;
    Inventory getInventory() const;
    void setXY(int x, int y);
    void move(sf::Keyboard::Key move);
    void displayPlayer();
    void changeWeapon(std::string name, int damage);
    void changeArmor(std::string name, int resistance);
    void leveling();
    void battle(Monster m, sf::RenderWindow& window);

private:
    std::string _name;
    int _currentHp, _hpMax;
    int _currentExp, _expMax;
    int _lvl;
    int _x,_y;
    Weapon _weapon;
    Armor _armor;
    Inventory _inventory;
};

#endif