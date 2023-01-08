#include "headers/item.hpp"
using namespace std;

Item::Item() : _name("inconnu"), _type("inconnu"), _x(0), _y(0)
{
}

Item::Item(string name, string type, int x, int y): _name(name), _type(type), _x(x), _y(y)
{
}

string Item::getName() const
{
    return _name;
}

string Item::getType() const
{
    return _type;
}

int Item::getX() const
{
    return _x;
}

int Item::getY() const
{
    return _y;
}

void Item::setXY(int x, int y)
{
    _x = x;
    _y = y;
}
