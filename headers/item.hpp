#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>

class Item
{
    public:
        Item();
        Item(std::string name, std::string type, int x, int y);
        std::string getName() const;
        std::string getType() const;
        int getX() const;
        int getY() const;
        void setXY(int x, int y);

    private:
        std::string _name;
        std::string _type;
        int _x;
        int _y;
};

#endif