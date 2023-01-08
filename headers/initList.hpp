#ifndef INIT_HPP
#define INIT_HPP

#include "weapon.hpp"
#include "armor.hpp"
#include "heal.hpp"
#include "monster.hpp"
#include "pnj.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>


class InitList
{
    public:
        InitList();
        ~InitList();
        void InitMonsters();
        void InitArmors();
        void InitWeapons();
        void InitHeals();
        void InitPnj();
        Monster* getMonsters() const;
        Armor* getArmors() const;
        Weapon* getWeapons() const;
        Heal* getHeals() const;
        Pnj* getPnj() const;

    private:
        Monster* _monsterList = new Monster[22];
        Armor* _armorList = new Armor[3];
        Weapon* _weaponList = new Weapon[10];
        Heal* _healList = new Heal[3];
        Pnj* _pnjList = new Pnj[3];
};

#endif