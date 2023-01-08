#include "headers/initList.hpp"
using namespace std;

InitList::InitList()
{
    InitMonsters();
    InitArmors();
    InitHeals();
    InitWeapons();
    InitPnj();
}

void InitList::InitMonsters()
{
    string myText;
    ifstream MyReadFile("items/Monster.txt");
    string delimiter = "|";
    string tabMonster[5];
    int j=0;

    while (getline(MyReadFile, myText))
    {
        size_t pos = 0;
        int i=0;
        string token;
        while ((pos = myText.find(delimiter)) != string::npos)
        {
            token = myText.substr(0, pos);
            tabMonster[i++] = token;
            myText.erase(0, pos + delimiter.length());
        }
        tabMonster[4] = myText;
        _monsterList[j++] = Monster(stoi(tabMonster[0]), tabMonster[1], stoi(tabMonster[2]), stoi(tabMonster[3]), stoi(tabMonster[4]));
    }

    MyReadFile.close();
}

Monster* InitList::getMonsters() const {
    return _monsterList;
}
Armor* InitList::getArmors() const {
    return _armorList;
}
Weapon* InitList::getWeapons() const {
    return _weaponList;
}
Heal* InitList::getHeals() const {
    return _healList;
}
Pnj* InitList::getPnj() const {
    return _pnjList;
}


void InitList::InitArmors()
{
    string myText;
    ifstream MyReadFile("items/armor.txt");
    string delimiter = "|";
    string tabArmor[2];
    int j=0;

    while (getline(MyReadFile, myText))
    {
        size_t pos = 0;
        int i=0;
        string token;
        while ((pos = myText.find(delimiter)) != string::npos)
        {
            token = myText.substr(0, pos);
            tabArmor[i++] = token;
            myText.erase(0, pos + delimiter.length());
        }
        tabArmor[1] = myText;
        _armorList[j++] = Armor(tabArmor[0], stoi(tabArmor[1]));
    }

    MyReadFile.close();
}

void InitList::InitWeapons()
{
    string myText;
    ifstream MyReadFile("items/weapons.txt");
    string delimiter = "|";
    string tabWeapon[3];
    int j=0;

    while (getline(MyReadFile, myText))
    {
        size_t pos = 0;
        int i=0;
        string token;
        while ((pos = myText.find(delimiter)) != string::npos)
        {
            token = myText.substr(0, pos);
            tabWeapon[i++] = token;
            myText.erase(0, pos + delimiter.length());
        }
        tabWeapon[2] = myText;
        _weaponList[j++] = Weapon(tabWeapon[0], stoi(tabWeapon[2]));
    }

    MyReadFile.close();
}

void InitList::InitHeals()
{
    string myText;
    ifstream MyReadFile("items/heals.txt");
    string delimiter = "|";
    string tabHeals[2];
    int j=0;

    while (getline(MyReadFile, myText))
    {
        size_t pos = 0;
        int i=0;
        string token;
        while ((pos = myText.find(delimiter)) != string::npos)
        {
            token = myText.substr(0, pos);
            tabHeals[i++] = token;
            myText.erase(0, pos + delimiter.length());
        }
        tabHeals[1] = myText;
        _healList[j++] = Heal(tabHeals[0], stoi(tabHeals[1]));
    }

    MyReadFile.close();
}

void InitList::InitPnj()
{
    string myText;
    ifstream MyReadFile("items/pnj.txt");
    string delimiter = "|";
    string tabPnj[2];
    int j=0;

    while (getline(MyReadFile, myText))
    {
        size_t pos = 0;
        int i=0;
        string token;
        while ((pos = myText.find(delimiter)) != string::npos)
        {
            token = myText.substr(0, pos);
            tabPnj[i++] = token;
            myText.erase(0, pos + delimiter.length());
        }
        tabPnj[1] = myText;
        _pnjList[j++] = Pnj(tabPnj[0], tabPnj[1]);
    }

    MyReadFile.close();
}

InitList::~InitList() {
    
}