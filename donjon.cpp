#include "headers/donjon.hpp"
using namespace std;

Donjon::Donjon() : Map(10, 10)
{
}

void Donjon::fillUpMap()
{
    _map[_sizeLongueur][_sizeLargeur/2] = 1;
    srand(time(0));
    int chance, chance2;
    int i = 0, j;
    while (i <= ((_sizeLongueur * _sizeLargeur) / 10))
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
    }
}