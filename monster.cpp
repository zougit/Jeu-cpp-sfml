#include "headers/monster.hpp"
using namespace std;

Monster::Monster() : _id(12), _name("goblin"), _damage(15), _hp(50), _exp(50), _x(2), _y(0), _status(0)
{
}

Monster::Monster(int id, string name, int hp, int damage, int exp) : _id(id), _name(name), _hp(hp), _damage(damage), _exp(exp), _status(0)
{
}

void Monster::displayMonster()
{
    string isAlive = _status == 0 ? "vivant" : "mort";
    cout << "name: " << _name << endl
         << "damage: " << _damage << endl
         << "hp: " << _hp << endl
         << "exp: " << _exp << endl
         << "status: " << isAlive << endl
         << endl;
}

void Monster::monsterDie()
{
    _status = 3;
}

void Monster::reviveMonster()
{
    if (_status > 0)
        _status -= 1;
}

int Monster::getHp() const
{
    return _hp;
}

int Monster::getStatus() const
{
    return _status;
}

int Monster::getExp() const
{
    return _exp;
}

int Monster::getDamage() const
{
    return _damage;
}

int Monster::getID() const
{
    return _id;
}

void Monster::setXY(int x, int y)
{
    _x = x;
    _y = y;
}

int Monster::getX() const 
{
    return _x;
}

int Monster::getY() const 
{
    return _y;
}

void Monster::recieveDamage(int damage)
{
    _hp -= damage;
}