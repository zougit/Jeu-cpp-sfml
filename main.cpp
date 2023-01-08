#include "headers/map.hpp"
#include "headers/initList.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

// items/outils
// inventaire
// craft
// pnj
// save
// stats
// TODO - list des monstres sur la map
void game()
{
    Player *p = new Player();
    Map map;
    InitList list;
    // string move("");
    int box;
    int *x = new int(0);
    int *y = new int(0);
    map.fillUpMap(list.getMonsters());
    // TODO - function play
    RenderWindow window(VideoMode(1200, 1200), "le jeu");
    window.setPosition(Vector2i(750, 50));


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            else if (event.type == Event::KeyPressed)
            {
                if (Keyboard::isKeyPressed(Keyboard::E))
                {
                    p->displayPlayer();
                }
                else
                {

                    Keyboard::Key move = event.key.code;
                    box = map.checkAround(move, *p, x, y);
                    if (box != 0)
                    {
                        map.checkAction(window,box, move, p, list.getMonsters(), x, y);
                    }
                    else
                    {
                        map.move(move, p);
                    }
                }
            }
        }
        map.displayMap(window);
        window.display();

        // Texture texture;
        // if (!texture.loadFromFile("grass.jpg"))
        // {
        //     cout << "error" << endl;
        //     window.close();
        // }

        // Sprite sprite(texture);
        // window.draw(sprite);
        // window.display();
        // while (Keyboard::isKeyPressed(Keyboard::N))
        // {
        //     // map.displayMap();
        //     // cout << "move (z,q,s,d) or check player (e)" << endl;
        //     // cin >> move;
        //     // if (Keyboard::isKeyPressed(Keyboard::N))
        //     // {
        //     //     break;
        //     // }
        //      if (event.type == Event::KeyPressed)
        //     {
        //     cout << event.type << endl;
        //         if (Keyboard::isKeyPressed(Keyboard::E))
        //         {
        //              p->displayPlayer();
        //         }
        //         else
        //         {
        //             box = map.checkAround(move, *p, x, y);
        //             if (box != 0)
        //             {
        //                 map.checkAction(box, move, p, list.getMonsters(), x, y);
        //             }
        //             else
        //             {
        //                 map.move(move, p);
        //             }
        //         }
        //     }
        // }
    }
    delete p;
    delete x;
    delete y;
}

void menu()
{
    int choix;
    cout << "Menu" << endl;
    cout << "1 - nouvelle partie" << endl;
    cout << "2 - charger partie" << endl;
    cout << "3 - quitter" << endl;
    cout << "votre choix : ";
    cin >> choix;
    switch (choix)
    {
    case 1:
        cout << "nouvelle partie commencé" << endl
             << endl;
        game();
        break;
    case 2:
        cout << "partie chargé" << endl;
        break;
    case 3:
        cout << "fin du jeu" << endl;
        return;
    default:
        cout << "y a que 3 choix soit pas débile\n"
             << endl;
        menu();
        break;
    }
}

int main()
{
    menu();
    return 0;
}