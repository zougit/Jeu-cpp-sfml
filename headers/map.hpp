#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "initList.hpp"
#include "item.hpp"

class Map {
    public:
        Map();
        Map(int longueur,int largeur);
        void move(sf::Keyboard::Key move, Player *p);
        void displayMap(sf::RenderWindow& window);
        void fillUpMap(Monster *monsters);
        void fillUpDonjon(Player * p);
        void respawn();
        int checkAround(sf::Keyboard::Key move, Player p, int *x, int *y);
        void checkAction(sf::RenderWindow& window, int box, sf::Keyboard::Key move, Player *p, Monster *monsters, int *x, int *y);
        int getIndex(int x, int y);
        int getMonster(int x, int y);

    protected:
        int _sizeLongueur;
        int _sizeLargeur;
        int _map[30][30];
        Item _element[100];
        Monster _monsterList[100];
};

#endif