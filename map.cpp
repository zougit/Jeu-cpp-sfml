#include "headers/map.hpp"
using namespace std;
using namespace sf;

Map::Map() : _sizeLongueur(30), _sizeLargeur(30)
{
    for (int i = 0; i < _sizeLongueur; i++)
    {
        for (int j = 0; j < _sizeLargeur; j++)
        {
            _map[i][j] = 0;
        }
    }
}

Map::Map(int longueur, int largeur) : _sizeLongueur(longueur), _sizeLargeur(largeur)
{
    if (_sizeLongueur > 0 && _sizeLargeur > 0)
    {
        for (int i = 0; i < _sizeLongueur; i++)
        {
            for (int j = 0; j < _sizeLargeur; j++)
            {
                _map[i][j] = 0;
            }
        }
    }
    else
    {
        cout << "size can't be 0" << endl;
    }
}

int Map::getIndex(int x, int y)
{
    for (int i = 0; i < 99; i++)
    {
        if (_element[i].getY() == y && _element[i].getX() == x)
        {
            return i;
        }
    }
    return -1;
}

int Map::getMonster(int x, int y)
{
    for (int i = 0; i < 99; i++)
    {
        if (_monsterList[i].getY() == y && _monsterList[i].getX() == x)
        {
            return i;
        }
    }
    return -1;
}

// TODO - display par 10x10
void Map::displayMap(RenderWindow& window)
{
    if (_sizeLongueur && _sizeLargeur)
    {
        Texture myTexture;
        if (!myTexture.loadFromFile("tileTest2.png"))
            cout << "Loading failure" << endl;

        Texture perso;
        if (!perso.loadFromFile("tilesetPerso.png"))
            cout << "Loading failure" << endl;

        Sprite mySprite(myTexture);
        Sprite persoSprite(perso);

        persoSprite.setTextureRect(IntRect(32, 0, 32, 32));
        persoSprite.setPosition(0, 0);
        Sprite player = persoSprite;

        persoSprite.setTextureRect(IntRect(128, 0, 32, 32));
        persoSprite.setPosition(0, 20);
        Sprite pnj = persoSprite;

        mySprite.setTextureRect(IntRect(0, 0, 40, 40));
        mySprite.setPosition(0, 0);
        Sprite grass = mySprite;

        mySprite.setTextureRect(IntRect(0, 80, 40, 40));
        mySprite.setPosition(0, 40);
        Sprite rock = mySprite;

        mySprite.setTextureRect(IntRect(40, 0, 40, 40));
        mySprite.setPosition(0, 80);
        Sprite sand = mySprite;

        mySprite.setTextureRect(IntRect(0, 40, 40, 40));
        mySprite.setPosition(0, 120);
        Sprite wood = mySprite;

        mySprite.setTextureRect(IntRect(80, 0, 40, 40));
        mySprite.setPosition(0, 160);
        Sprite wall = mySprite;

        for (int i = 0; i < _sizeLongueur; i++)
        {
            for (int j = 0; j < _sizeLargeur; j++)
            {
                if (_map[i][j] == 1)
                {
                    // cout << "\033[34m" << _map[i][j] << "\033[0m";
                    player.setPosition(j * 40, i * 40);
                    window.draw(player);
                }
                else if (_map[i][j] == 2)
                {
                    // cout << "\033[32m" << _map[i][j] << "\033[0m";
                    wood.setPosition(j * 40, i * 40);
                    window.draw(wood);
                }
                else if (_map[i][j] == 3)
                {
                    // cout << "\033[35m" << _map[i][j] << "\033[0m";
                    rock.setPosition(j * 40, i * 40);
                    window.draw(rock);
                }
                else if (_map[i][j] == 5)
                {
                    // cout << "\033[36m" << _map[i][j] << "\033[0m";
                    grass.setPosition(j * 40, i * 40);
                    window.draw(grass);
                    pnj.setPosition(j * 40, i * 40);
                    window.draw(pnj);
                }
                else if (_map[i][j] == 8)
                {
                    // cout << "\033[30m" << _map[i][j] << "\033[0m";
                    wall.setPosition(j * 40, i * 40);
                    window.draw(wall);
                }
                else if (_map[i][j] >= 12 && _map[i][j] <= 18)
                {
                    // cout << "\033[31m" << _map[i][j] - 11 << "\033[0m";
                }
                else
                {
                    // cout << _map[i][j];
                    grass.setPosition(j * 40, i * 40);
                    window.draw(grass);
                }
            }
            // cout << endl;
        }
        // cout << endl;
    }
    else
    {
        cout << "size can't be 0" << endl;
    }
    window.display();
}

// TODO - monstres par lvl
void Map::fillUpMap(Monster *monsters)
{
    _map[0][0] = 1;
    _map[0][1] = 5;
    // _map[3][0] = 8;

    srand(time(0));
    int chance, chance2;
    int i = 0, j, k = 0, l = 0;
    while (i <= ((_sizeLongueur * _sizeLargeur) / 100) * 5)
    {
        chance = 1 + (rand() % _sizeLongueur);
        chance2 = 1 + (rand() % _sizeLargeur);
        if (_map[chance][chance2] == 0)
        {
            _map[chance][chance2] = 2;
            _element[l] = Item("herbe", "plante", chance, chance2);
            l++;
            i++;
        }
        chance = 1 + (rand() % _sizeLongueur);
        chance2 = 1 + (rand() % _sizeLargeur);
        if (_map[chance][chance2] == 0)
        {
            _map[chance][chance2] = 3;
            _element[l] = Item("pierre", "minerai", chance, chance2);
            l++;
            i++;
        }

        if (i < ((_sizeLongueur * _sizeLargeur) / 100) * 3)
        {
            j = 12;
            while (j <= 18)
            {
                chance = 1 + (rand() % _sizeLongueur);
                chance2 = 1 + (rand() % _sizeLargeur);
                if (_map[chance][chance2] == 0)
                {
                    _map[chance][chance2] = j;
                    _monsterList[k] = monsters[j - 12];
                    _monsterList[k].setXY(chance, chance2);
                    // cout << _monsterList[k].getX() << endl;
                    // cout << _monsterList[k].getY() << endl;
                    j++;
                    k++;
                }
            }
        }
    }
}

void Map::fillUpDonjon(Player *p)
{
    _map[_sizeLongueur - 1][_sizeLargeur / 2] = 1;
    p->setXY(_sizeLongueur - 1, _sizeLargeur / 2);
    _map[_sizeLongueur - 1][(_sizeLargeur / 2) + 2] = 4;
    srand(time(0));
    int chance, chance2;
    int i = 0, j;
    while (i <= (_sizeLongueur * _sizeLargeur) / 100)
    {
        j = 12;
        while (j <= 18)
        {
            chance = 1 + (rand() % _sizeLongueur);
            chance2 = 1 + (rand() % _sizeLargeur);
            if (_map[chance][chance2] == 0)
            {
                _map[chance][chance2] = j;
                j++;
            }
        }
        i++;
    }
}

void Map::respawn()
{
    for (int i = 0; i < 99; i++)
    {
        if (_element[i].getX() > 0)
        {
            if (_element[i].getX() == 0 && _element[i].getType() == "plante")
            {
                _map[_element[i].getX()][_element[i].getY()] = 2;
            }

            if (_element[i].getX() == 0 && _element[i].getType() == "minerai")
            {
                _map[_element[i].getX()][_element[i].getY()] = 3;
            }
        }
        if (_monsterList[i].getStatus() > 0)
        {
            _monsterList[i].reviveMonster();
            if (_monsterList[i].getStatus() == 0)
            {
                _map[_monsterList[i].getX()][_monsterList[i].getY()] = _monsterList[i].getID();
            }
        }
    }
}

void Map::move(Keyboard::Key move, Player *p)
{
    _map[p->getX()][p->getY()] = 0;
    p->move(move);
    _map[p->getX()][p->getY()] = 1;
    respawn();
}

// TODO - faire mourir le monstre
void Map::checkAction(RenderWindow &window, int box, Keyboard::Key move, Player *p, Monster *monsters, int *x, int *y)
{
    if (box == 2)
    {
        int id = getIndex(p->getX() + (*x), p->getY() + (*y));
        _element[id];
        cout << _element[id].getType() << endl;
        // p->getInventory().addItem(_element[id], _element[id].getType());
        // cout << p->getInventory().getItem()[0][0].getName() << endl;
    }
    else if (box == 3)
    {
        int id = getIndex(p->getX() + (*x), p->getY() + (*y));
        cout << _element[id].getType() << endl;
        // p->getInventory().addItem(_element[id], _element[id].getType());
    }
    else if (box >= 12 && box <= 18)
    {
        int id = getMonster(p->getX() + (*x), p->getY() + (*y));
        // cout << "id: " << id << endl;
        // cout << "id monstre: " << _monsterList[id].getID() << endl;
        // cout << "id monstre map: " << box << endl;
        if (id != -1)
        {
            // cout << "monstre" << endl;
            p->battle(_monsterList[id], window);
            _monsterList[id].monsterDie();
            _map[_monsterList[id].getX()][_monsterList[id].getY()] = 0;
        }
        else
        {
            cout << "monster doesn't exist" << endl;
        }
    }
    else if (box == 5)
    {
        cout << "pnj" << endl;
    }
    else if (box == 4)
    {
        cout << "sortie" << endl;
        return;
    }
    else if (box == 8)
    {
        cout << "donjon" << endl;
        int oldx = p->getX(), oldy = p->getY();
        *x = 0;
        *y = 0;
        Map m(10, 20);
        m.fillUpDonjon(p);
        while (box != 4)
        {
            // m.displayMap();
            cout << "move (z,q,s,d) or check player (e)" << endl;
            if (move == 'e')
            {
                p->displayPlayer();
            }
            else
            {
                box = m.checkAround(move, *p, x, y);
                if (box != 0)
                {
                    m.checkAction(window, box, move, p, monsters, x, y);
                }
                else
                {
                    m.move(move, p);
                }
            }
        }
        p->setXY(oldx, oldy);
    }
    else if (box == -1)
    {
        cout << "error" << endl;
    }
    respawn();
}

int Map::checkAround(Keyboard::Key move, Player p, int *x, int *y)
{
    switch (move)
    {
    case Keyboard::Z:
        *x = -1;
        *y = 0;
        return p.getX() - 1 >= 0 ? _map[p.getX() - 1][p.getY()] : -1;
        break;
    case Keyboard::Q:
        *x = 0;
        *y = -1;
        return p.getY() - 1 >= 0 ? _map[p.getX()][p.getY() - 1] : -1;
        break;
    case Keyboard::S:
        *x = +1;
        *y = 0;
        return p.getX() + 1 <= _sizeLongueur - 1 ? _map[p.getX() + 1][p.getY()] : -1;
        break;
    case Keyboard::D:
        *x = 0;
        *y = +1;
        return p.getY() + 1 <= _sizeLargeur - 1 ? _map[p.getX()][p.getY() + 1] : -1;
        break;
    default:
        return -1;
        break;
    }
}