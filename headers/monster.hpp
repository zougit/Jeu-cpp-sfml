#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <iostream>

class Monster {
    public:
        Monster();
        Monster(int id, std::string name, int hp, int damage, int exp);
        int getHp() const;
        int getStatus() const;
        int getExp() const;
        int getDamage() const;
        int getID() const;
        void displayMonster();
        void monsterDie();
        void reviveMonster();
        void recieveDamage(int damage);
        void setXY(int x, int y);
        int getX() const;
        int getY() const;
        
    private:
        int _id;
        std::string _name;
        int _damage;
        int _hp;
        int _exp;
        int _x;
        int _y;
        int _status;
};

#endif